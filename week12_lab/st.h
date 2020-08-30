#ifndef ST_H_DEFINED
#define ST_H_DEFINED
#include "item.h"
typedef struct symboltable *ST;
typedef struct STnode* link;
ST STinit(int);
void STinsert(ST, Item);
Item STsearch(ST, Key);
void STdelete(ST, Key);
void STdisplay(ST, FILE*);
link NEW(Item, link);
link NEW2(Item,link);
link list_unique(ST);
link next_link(link);
Key getKEY(link);
#endif
