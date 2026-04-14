#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gpcp.h"

void print_level(int depth) {
    char indent[16];
    memset(indent, ' ', depth * 2);
    indent[depth * 2] = '\0';
    
    // Note: We need a way to list nodes in current level. 
    // Since we don't have an iterator, this would require 
    // extending GPCP. 
    // For this demonstration, we'll just show the level entry.
    printf("%sEntering level...\n", indent);
}

Options test_options[] = {
    {"root", PARENT, NULL},
    {"key1", FLOAT, "root"},
    {"key2", STRING, "root"},
    {"parent1", PARENT, "root"},
    {"sub1", FLOAT, "parent1"},
    {"sub2", FLOAT, "parent1"},
    {"level1", PARENT, "root"},
    {"nested", INTEGER, "level1"},
    {"parent2", PARENT, "root"},
    {"sub3", FLOAT, "parent2"},
    {NULL, 0, NULL}
};

int main() {
    Data *data;
    GPCP_RegisterOptions(test_options);
    
    if (GPCP_ReadFile("test_edge.conf", &data) != 0) {
        printf("Error reading config file.\n");
        return -1;
    }
    
    printf("root:\n");
    if (GPCP_EnterLevel("root", 0) == -1) {
        printf("  Error entering 'root' level.\n");
        GPCP_FreeData(&data);
        return -1;
    }

    float fval;
    int ival;
    char *str;

    if (GPCP_GetValue("key1", &fval) == 0) printf("  key1: %f [FLOAT]\n", fval);
    if (GPCP_GetValue("key2", &str) == 0) { printf("  key2: %s [STRING]\n", str); free(str); }

    if (GPCP_EnterLevel("parent1", 0) == 0) {
        printf("  parent1:\n");
        if (GPCP_GetValue("sub1", &fval) == 0) printf("    sub1: %f [FLOAT]\n", fval);
        if (GPCP_GetValue("sub2", &fval) == 0) printf("    sub2: %f [FLOAT]\n", fval);
        GPCP_ExitLevel();
    }

    if (GPCP_EnterLevel("level1", 0) == 0) {
        printf("  level1:\n");
        if (GPCP_GetValue("nested", &ival) == 0) printf("    nested: %d [INTEGER]\n", ival);
        GPCP_ExitLevel();
    }

    if (GPCP_EnterLevel("parent2", 0) == 0) {
        printf("  parent2:\n");
        if (GPCP_GetValue("sub3", &fval) == 0) printf("    sub3: %f [FLOAT]\n", fval);
        GPCP_ExitLevel();
    }

    GPCP_ExitLevel();
    GPCP_FreeData(&data);
    return 0;
}
