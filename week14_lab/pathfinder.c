#include "graph.h"
#include "pathfinder.h"
static graph_t *new_node(graph_t*, int);
static void new_edge(graph_t*, int, int, int, int);
void sho_path(graph_t* g, int nv){
 int v1, v2; graph_t *prim_g = NULL;
 wanted(stdin, stdout, &v1, &v2);
 prim_g = prim(v1, g, nv);
 display(prim_g, stdout);
}
graph_t *prim(int start, graph_t *g, int nv){
 int weight = 0; edge_t *u;
 graph_t *source, *prim_g = NULL,*t1,*t2;
 source = graph_find(g, nv, start);
 source->dist = 0;
 u = get_min(g);
 while(u != NULL){
  prim_g = add_node(prim_g, u->src->id, weight);
  t1 = graph_find(g, nv ,prim_g->id);
  t1->dist = weight;
  printf("FROM: %d.TO: %d\n", prim_g->id, u->dst->id);
  weight = weight + u->weight;
  prim_g = add_node(prim_g, u->dst->id, weight);
  t2 = graph_find(g,nv,prim_g->id);
  t2->dist = weight;
  u = get_min(g);
 }
 return prim_g;
}
graph_t *add_node(graph_t *g, int id, int distance){
 graph_t *temp = new_node(g, id);
 temp->dist = distance;
 return temp;
}
edge_t *get_min(graph_t *g){// -chooses the cutting light edge
 edge_t *e_temp, *min_e = NULL;
 int min_weight = INT_MAX; graph_t *temp = g;
 while(temp != NULL){
  if(temp->dist != INT_MAX){
   e_temp = temp->head;
   while(e_temp != NULL &&
   e_temp->dst->dist == INT_MAX){
    if(min_weight > e_temp->weight){
     min_weight = e_temp->weight;
     min_e = e_temp;
    }
   e_temp = e_temp->next;
   }
  }
  temp = temp->next;
 }
 return min_e;
}
graph_t *remove_edge(edge_t *e, graph_t *g){//probably not working
 if(g == NULL) return NULL;
 graph_t *save = g, *temp = g, *head = g;
 while(temp != NULL){
  if(temp->id == e->src->id){
   save->next = temp->next;
   return head;
  }
  save = temp;
  temp = temp->next;
 }
 return head;
}
graph_t *copy_g(graph_t *g, int nv){//DONE SO FAR
 graph_t *temp, *n = g; struct edge *e = NULL; int i;
 for(i = nv-1; i >= 0; i--) temp = new_node(temp, i);
 for(i = nv-1; i >= 0; i--){
  e = n->head;
  while(e != NULL){
   new_edge(temp, nv, i, e->dst->id, e->weight);
   new_edge(temp, nv, e->dst->id, i, e->weight);//might cause a problem
   e = e->next;
  }
  n = n->next;
 }
 return temp;
}
static graph_t *new_node(graph_t *g, int id){
  graph_t *n;
  n = (graph_t *)util_malloc(sizeof(graph_t));
  n->id = id;
  n->color = WHITE;
  n->dist = INT_MAX;
  n->pred = NULL;
  n->scc = n->td = n->tq = -1;
  n->head = NULL;
  n->next = g;
  return n;
}
static void new_edge(graph_t *g, int nv, int i, int j, int weight){
 graph_t *src, *dst;
 edge_t *e;
 src = graph_find(g, nv, i);
 dst = graph_find(g, nv, j);
 e = (edge_t *)util_malloc(sizeof(edge_t));
 e->dst = dst;
 e->src = src;
 e->weight = weight;
 e->next = src->head;
 src->head = e;
}
void wanted(FILE *fin,FILE *fout, int *v1, int *v2){
 fprintf(fout, "\nEnter 2 IDs:\n");fscanf(fin, "%d %d", v1, v2);
}
void display(graph_t *g, FILE *fp){
 if(g == NULL) return;
 struct edge *e = g->head;
 while(e != NULL){
  fprintf(fp,"\nNode:%d->%d %d",g->id, e->dst->id, e->weight);
  e = e->next;
 }
 display(g->next, fp);
}
void print_error(char *err, int flag){
 fprintf(stderr, "\n%s\n", err); if(flag) exit(FAILURE);
}
