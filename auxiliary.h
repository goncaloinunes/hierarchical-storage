#ifndef AUXILIARY_H_INCLUDE
#define AUXILIARY_H_INCLUDE


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Represents the terminal character when reading the user's input,
indicating that spaces are allowed. */
#define SPACING '\n' 
/* Represents the terminal character when reading the user's input,
indicating that spaces are not allowed. */
#define NO_SPACING ' '

/* Indicates that no character has been found yet. */
#define NO_CHAR_FOUND 0
/* Indicates that a character was found. */
#define CHAR_FOUND 1

#define COMMAND_HELP "help" /* Command 'Help' string */
#define COMMAND_QUIT "quit" /* Command 'Quit' string */
#define COMMAND_SET "set" /* Command 'Set' string */
#define COMMAND_PRINT "print" /* Command 'Print' string */
#define COMMAND_FIND "find" /* Command 'Find' string */
#define COMMAND_LIST "list" /* Command 'List' string */
#define COMMAND_SEARCH "search" /* Command 'Search' string */
#define COMMAND_DELETE "delete" /* Command 'Delete' string */
#define COMMAND_HELP_DESCRIPTION "Imprime os comandos disponiveis."
#define COMMAND_QUIT_DESCRIPTION "Termina o programa."
#define COMMAND_SET_DESCRIPTION "Adiciona ou modifica o valor a armazenar."
#define COMMAND_PRINT_DESCRIPTION "Imprime todos os caminhos e valores."
#define COMMAND_FIND_DESCRIPTION "Imprime o valor armazenado."
#define COMMAND_LIST_DESCRIPTION "Lista todos os componentes imediatos de um sub-caminho."
#define COMMAND_SEARCH_DESCRIPTION "Procura o caminho dado um valor."
#define COMMAND_DELETE_DESCRIPTION "Apaga um caminho e todos os subcaminhos."



/* Structures */


typedef struct Directory {
    char *name;
    char *value;
} Directory;


typedef struct Node {
    Directory directory;
    struct Node *firstChild;
    struct Node *nextSibling;
} Node;











/* Function Prototipes */
char *read_input(char end_char);
void check_memory(void *memory);
char *safe_realloc(void *ptr, int size);
void clear_line();


Node *init_tree();
Node *new_node(Directory directory);
Node *insert_sibling(Node *node, Directory directory);
Node *insert_child(Node *node, Directory directory);
void print_tree(Node *tree);
void *create_node_with_path(Node *root, char *path);

void handle_command_help();
void handle_command_set(Node *root);

#endif