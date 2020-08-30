#ifndef _TREE_PUBLIC_INCLUDED
#define _TREE_PUBLIC_INCLUDED
#include "item.h"
#include "data.h"
#include "st.h"
#define PREORDER -1
#define INORDER   0
#define POSTORDER 1
typedef struct node node_t;
data_t getData(node_t*);
node_t *createEmptyTree();
node_t *readTree(FILE*);
node_t *searchI(node_t*, data_t);
node_t *searchR(node_t*, data_t);
node_t *treeMinI(node_t*);
node_t *treeMinR(node_t*);
node_t *treeMaxI(node_t*);
node_t *treeMaxR(node_t*);
node_t *insert(node_t*,data_t);
node_t *delete(node_t*,data_t);
/**ADDED**/
int get_height(node_t*, char*, int);
void writeTree(FILE*, node_t*, int);
void freeTree(node_t*);
void print_t(int, node_t*, int);
void tree_to_hash(node_t*, ST);
/**ADDED**/
#endif
