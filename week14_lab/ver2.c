#include "ver2.h"
void graph_dfs(graph_t *g, int nv, graph_t *source, graph_t *end){
 int id = 0, weight = 0;graph_t *n = source, *head = NULL;solution *sol;
 source->dist = 0;
 if(graph_dfs_r(n, nv, source, end, &weight, sol,id, &head))
  fprintf(stdout,"TOTAL WEIGHT :%d\n", weight);
/* while(n != NULL){
  printf("%d\n", n->id);
  n = n->next;
 }*/
}
int graph_dfs_r(graph_t *list, int nv, graph_t *source, graph_t *end, int *weight, solution *sol, int id, graph_t **head){
 edge_t *e; graph_t *dest = NULL;
 if(source == end) return 1;
 source->color = GREY;
 e = source->head;
 while(e != NULL){
  dest = e->dst;
  *weight = *weight + e->weight;
  if(dest->color == WHITE){
   dest->dist = *weight;
   printf("node:%d weight:%d\n",dest->id,dest->dist);
  }
  if(dest->color == GREY) printf("some\n");
  if(graph_dfs_r(list,nv,dest,end,weight,sol,id,head))return 1;
  *weight = *weight - e->weight;
  e = e->next;
 }
 source->color = BLACK;
 return 0;
}
graph_t *remove_list(graph_t *node, graph_t* head){
 graph_t *t1 = head, *t2;
 while(t1 != NULL){
  if(t1->next->id == node->id){
   t2 = t1->next->next;
   t1->next = t2;
   return head;
  }
 }
}
graph_t **add_list(graph_t* node, graph_t **head){
 printf("%d\n",node->id);
 graph_t **t = head;
 if(*t == NULL){
  *t = node;
  return t;
 }
 while((*t)->next != NULL) (*t) = (*t)->next;
 (*t)->next = node;
 return head;
}
void add_sol(solution *sol, graph_t *g, int id){
/* solution *s = sol; graph_t *t;
 while(s->id != id && s->next != NULL)s = s->next;
 if(s->id == id)*/
}
edge_t *get_min(graph_t *source){
 edge_t *tmp = NULL, *e = source->head;
 int min = INT_MAX;
 while(e != NULL){
  if(e->weight < min && !e->marked){
   tmp = e;
   tmp->marked = 1;
   min = e->weight;
  }
  e = e->next;
 }
 return tmp;
}
void wanted(FILE *fin,FILE *fout, int *v1, int *v2){fprintf(fout, "\nEnter 2 IDs:\n");fscanf(fin, "%d %d", v1, v2);}

