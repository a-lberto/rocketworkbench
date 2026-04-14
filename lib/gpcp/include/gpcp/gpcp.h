#ifndef GPCP_H
#define GPCP_H

typedef enum {
    FLOAT,
    INTEGER,
    STRING,
    PARENT
} OptionType;

typedef struct {
    char *name;
    OptionType type;
    char *parent;
} Options;

typedef struct GPCP_Node {
    char *key;
    char *value;
    OptionType type;
    struct GPCP_Node *children;
    struct GPCP_Node *parent;
    struct GPCP_Node *next_sibling;
} GPCP_Node;

typedef struct {
    GPCP_Node *root;
    GPCP_Node *current_node;
} Data;

void GPCP_RegisterOptions(Options *options);
int GPCP_ReadFile(char *filename, Data **data);
int GPCP_EnterLevel(char *name, int index);
int GPCP_ExitLevel(void);
int GPCP_GetValue(char *name, void *value);
int GPCP_NumParent(char *name);
void GPCP_FreeData(Data **data);

#endif
