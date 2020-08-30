#ifndef _TREE_PUBLIC_INCLUDED
#define _TREE_PUBLIC_INCLUDED
#include "dataInt.h"
#define PREORDER  -1
#define INORDER    0
#define POSTORDER  1
typedef struct node node_t;
data_t getData (node_t *);
node_t *createEmptyTree ();
node_t *readTree(FILE *);
node_t *searchI (node_t *, data_t);
node_t *searchR (node_t *, data_t);
node_t *treeMinI (node_t *);
node_t *treeMinR (node_t *);
node_t *treeMaxI (node_t *);
node_t *treeMaxR (node_t *);
node_t *insert(node_t *, data_t);
node_t *delete(node_t *, data_t);
void writeTree(FILE *, node_t *, int);
void freeTree(node_t *);
/*Edit */
int visit(node_t*,int);
int count_all(node_t*);
void wrap_visit(node_t*,int,int);
void print_array(int*,int);
int get_height(node_t*);
int path_count(node_t*);
void wrap_path(node_t*,int*,int);
void wrap_level(node_t*,int**,int);
void count_level(node_t*,int*,int);
void countNode(node_t*,int**);
#endif

