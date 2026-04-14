#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gpcp.h"

static Options *registered_options = NULL;
static Data *global_data = NULL;
static GPCP_Node *stack[10];
static int stack_ptr = 0;

void GPCP_RegisterOptions(Options *options) {
    registered_options = options;
}

static GPCP_Node *create_node(char *key, GPCP_Node *parent) {
    GPCP_Node *node = (GPCP_Node *)calloc(1, sizeof(GPCP_Node));
    node->key = strdup(key);
    node->parent = parent;
    node->next_sibling = NULL;
    return node;
}

static void parse_node(FILE *f, GPCP_Node *parent) {
    char buf[256];
    GPCP_Node *last = NULL;
    int c;
    
    while (1) {
        // Skip whitespace and comments
        while ((c = fgetc(f)) != EOF) {
            if (c == '#') {
                while ((c = fgetc(f)) != EOF && c != '\n');
            } else if (!isspace(c)) {
                ungetc(c, f);
                break;
            }
        }
        
        if (c == EOF || c == ')') break;

        if (fscanf(f, " %255[^=(), \n\t\r#]", buf) != 1) break;
        
        GPCP_Node *node = create_node(buf, parent);
        if (last) last->next_sibling = node;
        else parent->children = node;
        last = node;

        c = fgetc(f);
        while (c == ' ' || c == '\n' || c == '\t' || c == '\r') c = fgetc(f);
        
        if (c == '=') {
            c = fgetc(f);
            while (c == ' ' || c == '\n' || c == '\t' || c == '\r') c = fgetc(f);
            if (c == '(') {
                node->type = PARENT;
                parse_node(f, node);
            } else {
                ungetc(c, f);
                fscanf(f, "%255[^,)\n\r]", buf);
                node->value = strdup(buf);
                node->type = FLOAT;
            }
        }
        
        c = fgetc(f);
        while (c == ' ' || c == '\n' || c == '\t' || c == '\r') c = fgetc(f);
        if (c == ')') break;
        if (c != ',') ungetc(c, f);
    }
}

int GPCP_ReadFile(char *filename, Data **data) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1;
    *data = (Data *)calloc(1, sizeof(Data));
    (*data)->root = create_node("root", NULL);
    parse_node(f, (*data)->root);
    fclose(f);
    global_data = *data;
    global_data->current_node = (*data)->root;
    stack[stack_ptr++] = global_data->current_node;
    return 0;
}

int GPCP_EnterLevel(char *name, int index) {
    GPCP_Node *curr = global_data->current_node;
    GPCP_Node *child = curr->children;
    int count = 0;
    while (child) {
        if (strcmp(child->key, name) == 0) {
            if (count == index) {
                stack[stack_ptr++] = global_data->current_node;
                global_data->current_node = child;
                return 0;
            }
            count++;
        }
        child = child->next_sibling;
    }
    return -1;
}

int GPCP_ExitLevel(void) {
    if (stack_ptr <= 1) return -1;
    global_data->current_node = stack[--stack_ptr];
    return 0;
}

int GPCP_GetValue(char *name, void *value) {
    GPCP_Node *curr = global_data->current_node;
    GPCP_Node *child = curr->children;
    OptionType expected_type = FLOAT;
    if (registered_options) {
        for (int i = 0; registered_options[i].name != NULL; i++) {
            if (strcmp(registered_options[i].name, name) == 0) {
                expected_type = registered_options[i].type;
                break;
            }
        }
    }
    while (child) {
        if (strcmp(child->key, name) == 0 && child->value) {
            if (expected_type == STRING) {
                char *s = strdup(child->value);
                if (s[0] == '"') {
                    memmove(s, s + 1, strlen(s));
                    s[strlen(s) - 1] = '\0';
                }
                *(char **)value = s;
            } else if (expected_type == INTEGER) {
                *(int *)value = atoi(child->value);
            } else {
                *(float *)value = (float)atof(child->value);
            }
            return 0;
        }
        child = child->next_sibling;
    }
    return -1;
}

int GPCP_NumParent(char *name) {
    GPCP_Node *curr = global_data->current_node;
    GPCP_Node *child = curr->children;
    int count = 0;
    while (child) {
        if (strcmp(child->key, name) == 0) count++;
        child = child->children;
    }
    return count;
}

static void free_nodes(GPCP_Node *node) {
    if (!node) return;
    GPCP_Node *child = node->children;
    while (child) {
        GPCP_Node *next = child->next_sibling;
        free_nodes(child);
        child = next;
    }
    free(node->key);
    free(node->value);
    free(node);
}

void GPCP_FreeData(Data **data) {
    if (*data) {
        free_nodes((*data)->root);
        free(*data);
        *data = NULL;
    }
}
