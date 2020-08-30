#include "client.h"
//remove remove_p funcction finds distance in 2 nodes
void wanted(FILE *fin,FILE *fout, int *v1, int *v2){fprintf(fout, "\nEnter 2 IDs:\n");fscanf(fin, "%d %d", v1, v2);}
void shortest_path(graph_t *g, int nv){
 graph_t *start, *stop;
 int v1, v2; path_t *p = NULL;
 wanted(stdin,stdout,&v1,&v2);
 start = graph_find(g,nv, v1);
 stop = graph_find(g, nv, v2);
 graph_bfs(g,nv,start,stop,&p);
 display_path(p);
}
void display_path(path_t *p){//done
 if(p == NULL) return;
 printf("NODE[%d] DISTANCE = %d\n",
 p->vertex->id, p->vertex->dist);
 display_path(p->next);
}
path_t *add(path_t *p, graph_t *node){
 path_t *new_p, *t = p;
 new_p = malloc(sizeof(path_t));
 new_p->vertex = node;
 new_p->next = NULL;
 if(p == NULL) return new_p;
 while(t->next != NULL) t = t->next;
 t->next = new_p;
 return p;
}
path_t *remove_p(path_t *p, graph_t* g){
 if(p == NULL || g == NULL) return NULL;
 graph_t *t = g; path_t *s, *temp = p;
 if(p->vertex->id == g->id){
  temp = temp->next;
  return temp;
 }
 while(temp->next != NULL && temp->next->vertex->id != g->id) temp = temp->next;
 if(temp->next == NULL) return NULL;
 s = temp;
 temp = temp->next;
 s->next = temp->next;
 return p;
}
int in_list(path_t *p, int id){
 path_t *t = p;
 while(t != NULL){
  if(t->vertex->id == id) return 1;
  t = t->next;
 }
 return 0;
}
int graph_bfs(graph_t *g, int nv, graph_t *source ,graph_t *end, path_t **p){
 int weight = 0;
 queue_t *qp = queue_init(nv);
 graph_t *d; edge_t *e;
 source->color = GREY;
 source->dist = weight;
 source->pred = NULL;
 *p = add(*p, source);
 queue_put(qp,(void*)source);
 while(!queue_empty_m(qp)){
  queue_get(qp, (void **)&source);
  e = source->head;
  weight = source->dist;
  while(e != NULL){
   d = e->dst;
   weight = source->dist + e->weight;
   if(d->dist > weight){
    d->dist = weight;
    if(in_list())
    *p = add(*p, d);
   }
   d->pred = source;
   if(d->color != BLACK) queue_put(qp,(void*)d);
   weight = weight - e->weight;
   e = e->next;
  }
  source->color = BLACK;
  *p = remove_p(*p, source);
 }
 queue_dispose(qp, NULL);
 return 0;
}
void display(graph_t *g, FILE *fp, int id){
 if(g == NULL) return;
 graph_t *n = g;
 if(n->color != WHITE && n->id == id) printf("%2d: DISTANCE:%d \n", n->id, n->dist);
 display(n->next, fp, id);
}
void print_error(char *err, int flag){fprintf(stderr, "\n%s\n", err); if(flag) exit(FAILURE);}


