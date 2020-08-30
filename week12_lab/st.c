#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "st.h"
typedef struct STnode* link;
struct STnode{
 Item item;
 link next;
};
struct symboltable{
 link *heads;
 int M;
 link z;
};
/**ADDED**/
Key getKEY(link node){return(KEYget(node->item));}
link next_link(link node){return(node->next);}
link list_unique(ST table){//DONE
 link end = NULL,head = NULL,curr = NULL;int i = 0;
 while(i < table->M){
 curr = table->heads[i];
  while(!ITEMcheckvoid(curr->item)&&
  !ITEMcheckvoid(curr->next->item)){
   if(head == NULL){head = NEW(curr->item, head); end = head;}
   else{end = NEW2(curr->item, end); end = end->next;}
   curr = curr->next;
  }
  i++;
 }
 end->next = NULL;
 return head;
}
link NEW2(Item item,link node){
 link x = malloc(sizeof *x);
 x->item = item;
 node->next = x;
 return node;
}
/**ADDED**/
link NEW(Item item,link next){
 link x = malloc(sizeof *x);
 x->item = item;
 x->next = next;
 return x;
}
ST STinit(int maxN){
 int i;
 ST st = malloc(sizeof *st);
 st->M = maxN / 5;
 st->heads = malloc((st->M) * sizeof(link));
 st->z = NEW(ITEMsetvoid(), NULL);
 for(i = 0; i < st->M; i++)
  st->heads[i] = st->z;
 return st;
}
int hash(Key v, int M){
 int h = 0, base = 127;
 for(;*v != '\0'; v++)
   h = (base * h + *v) % M;
 return h;
}
int hashU(Key v, int M){
 int h, a = 31415, b = 27183;
 for(h = 0; *v != '\0'; v++, a = a*b % (M-1))
   h = (a*h + *v) % M;
 return h;
}
void STinsert(ST st, Item item){
 int i = hashU(KEYget(item), st->M);
 printf("hash = %d [%s]\n", i,KEYget(item));
 st->heads[i] = NEW(item, st->heads[i]);
}
Item STsearch_r(link t, Key k, link z){
  if(t == z) return ITEMsetvoid();
  if((KEYcompare(KEYget(t->item), k))==0)return t->item;
  return STsearch_r(t->next, k, z);
}
Item STsearch(ST st, Key k){
  return STsearch_r(st->heads[hash(k, st->M)], k, st->z);
}
link deleteR(link x, Key k){
 if( x == NULL ) return NULL;
 if((KEYcompare(KEYget(x->item),k))==0){
   link t = x->next;
   free(x);
   return t;
 }
 x->next = deleteR(x->next, k);
 return x;
}
void STdelete(ST st, Key k){
 int i = hash(k, st->M);
 st->heads[i] = deleteR(st->heads[i], k);
}
void visitR(link h, link z){
 if(h == z) return;
 ITEMshow(h->item);
 visitR(h->next,z);
}
void STdisplay(ST st,FILE *f){
 int i;
 for(i = 0; i < st->M; i++){
   fprintf(f, "st->heads[%d] = ", i);
   visitR(st->heads[i], st->z);
   fprintf(f, "\n");
 }
}
