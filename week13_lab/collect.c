#include "graph.h"
#include "queuePublic.h"
/**SWAPPABLE WITH ORIGINAL BFS**/
void graph_bfs_count(graph_t *g, int nv, graph_t *n){
  queue_t *qp = queue_init(nv);graph_t *d; edge_t *e;
  n->color=GREY;n->dist = 0;n->pred = NULL;int c = 1;
  queue_put(qp, (void*)n);
  while(!queue_empty_m(qp)){
    queue_get(qp, (void **)&n);
    e = n->head;
    while(e != NULL){
      d = e->dst;
      if(d->color == WHITE){
        d->color = GREY;c++;
        d->dist = n->dist + 1;
        d->pred = n;
        queue_put(qp, (void *)d);
      }
      e = e->next;
    }
    n->color = BLACK;
  }
  printf("\n----------%d---------\n",c);
  queue_dispose(qp, NULL);
}
int graph_bfs_distance(graph_t *g, int nv, graph_t *n){
  queue_t *qp = queue_init(nv); graph_t *d;  edge_t *e;
  n->color=GREY;n->dist = 0;n->pred = NULL;int max = 0;
  queue_put(qp, (void*)n);
  while(!queue_empty_m(qp)){
    queue_get(qp, (void **)&n);
    e = n->head;
    while(e != NULL){
      d = e->dst;
      if(d->color == WHITE){
        d->color = GREY;
        d->dist = n->dist + 1;
        d->pred = n;
        queue_put(qp, (void *)d);
      }
      if(d->dist > max) max = d->dist;
      e = e->next;
    }
    n->color = BLACK;
  }
  queue_dispose(qp, NULL);
 return max;
}
/**SWAPPABLE WITH ORIGINAL DFS_R **/
int graph_dfs_type(graph_t *g, int nv, graph_t *n, int currTime,int *tree,int *forw,int *back,int *cross){
  edge_t *e; graph_t *tmp;
  n->color = GREY;
  n->td = ++currTime;
  e = n->head;
  while(e != NULL){
    tmp = e->dst;
    switch(tmp->color){
      case WHITE: printf("%d -> %d : T\n", n->id, tmp->id); (*tree)++; break;
      case GREY : printf("%d -> %d : B\n", n->id, tmp->id); (*back)++; break;
      case BLACK: if(n->td < tmp->td){ printf("%d -> %d : F\n", n->id, tmp->id);(*forw)++;}
                  else{printf("%d -> %d : C\n", n->id, tmp->id);(*cross)++;}
    }
    if (tmp->color == WHITE){
      tmp->pred = n;
      currTime = graph_dfs_type(g, nv, tmp, currTime,tree,forw,back,cross);
    }
    e = e->next;
  }
  n->color = BLACK;
  n->tq = ++currTime;
  return currTime;
}
int graph_dfs_depth(graph_t *g, int nv, graph_t *n, int currTime, int *height,int *sub_h){
 edge_t *e; graph_t *tmp;
 n->color = GREY;
 n->td = ++currTime;
 e = n->head;
if(*sub_h > *height) *height = *sub_h;
 while(e != NULL){
   tmp = e->dst;
   switch(tmp->color){
     case WHITE: printf("%d -> %d : T\n", n->id, tmp->id); break;
     case GREY : printf("%d -> %d : B\n", n->id, tmp->id); break;
     case BLACK: if (n->td < tmp->td)printf("%d -> %d : F\n", n->id, tmp->id);
                 else printf("%d -> %d : C\n", n->id, tmp->id);
   }
   if(tmp->color == WHITE){
     tmp->pred = n; (*sub_h)++;
     currTime = graph_dfs_depth(g, nv, tmp, currTime, height,sub_h);
     (*sub_h)--;
   }
   e = e->next;
 }
 n->color = BLACK;
 n->tq = ++currTime;
 return currTime;
}
static void new_edge(graph_t *g, int nv, int i, int j, int weight){
 graph_t *src, *dst;
 edge_t *e;
 src = graph_find(g, nv, i);
 dst = graph_find(g, nv, j);
 e = (edge_t *)util_malloc(sizeof(edge_t));
 e->dst = dst;
 e->weight = weight;
 e->next = NULL;
 e->next = src->head;
 src->head = e;
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
graph_t *graph_transpose(graph_t *g, int nv){
 graph_t *trans_g = NULL, *temp = g; int i;
 for(i = nv-1; i >= 0; i--) trans_g = new_node(trans_g, i);
 while(temp != NULL){
  while(temp->head != NULL){
   new_edge(trans_g, nv, temp->head->dst->id, temp->id, temp->head->weight);
   temp->head = temp->head->next;
  }
  temp = temp->next;
 }
return trans_g;
}
