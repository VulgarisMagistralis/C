#include <stdio.h>
#include "queuePublic.h"
#include "graph.h"
/* function prototypes */
void graph_bfs(graph_t *g, int nv, graph_t *n);
void graph_dfs(graph_t *g, int nv, graph_t *n);
int graph_dfs_r(graph_t *g, int nv, graph_t *n, int currTime);
/*ADDED*/
int graph_dfs_type(graph_t*, int, graph_t*, int,int*,int*,int*,int*);
int graph_dfs_depth(graph_t*, int, graph_t*, int, int*,int*);
void graph_bfs_count(graph_t*, int, graph_t*);
int graph_bfs_distance(graph_t*, int, graph_t*);
graph_t *graph_transpose(graph_t*, int);
/*ADDED*/
/**main program*/
int main(int argc, char *argv[]){
 graph_t *g, *n, *tmp, *src;edge_t *e; int i, nv;
 /**ADDED**/
 int tree_no, for_no, back_no, cross_no, max;
 /**ADDED**/
 util_check_m(argc >= 2, "missing parameter.");
 g = graph_load(argv[1], &nv);
 g = graph_transpose(g, nv);
 printf("Initial vertex? "); scanf("%d", &i);
 printf("Incoming/Outgoing Edges\n");
 src = graph_find(g, nv, i);
 /* print out-going edges */
 e = src->head;
 while(e != NULL){
  printf("%d -> %d (%d)\n", i, e->dst->id, e->weight);
  e = e->next;
 }
 /* BFS */
 printf("BFS\n");
 src = graph_find(g, nv, i);
 // Reset fields
 for(tmp = g; tmp != NULL; tmp = tmp->next){
  tmp->color = WHITE;
  tmp->dist = INT_MAX;
  tmp->pred = NULL;
  tmp->scc = tmp->td = tmp->tq = -1;
 }
 //graph_bfs(g, nv, src);
 //graph_bfs_count(g, nv, src);
 max = graph_bfs_distance(g, nv, src);
 printf("\n----------------%d\n", max);
 /* print reachable nodes with info */
 n = g;
 printf("List of vertices:\n");
 while(n != NULL){
  if(n->color != WHITE) printf("%2d: [%d] (%d)\n", n->id, n->dist, n->pred ? n->pred->id : -1);
  n = n->next;
 }
 /* DFS */
 printf ("DFS\n");
 src = graph_find(g, nv, i);
 // Reset fields
 for(tmp = g; tmp != NULL; tmp = tmp->next){
  tmp->color = WHITE;
  tmp->dist = INT_MAX;
  tmp->pred = NULL;
  tmp->scc = tmp->td = tmp->tq = -1;
 }
 graph_dfs(g, nv, src);
 graph_dispose(g, nv);
 return EXIT_SUCCESS;
}
/**perform BFS from vertex n*/
void graph_bfs(graph_t *g, int nv, graph_t *n){
  queue_t *qp = queue_init(nv);
  graph_t *d; edge_t *e;
  n->color = GREY; n->dist = 0; n->pred = NULL;
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
      e = e->next;
    }
    n->color = BLACK;
  }
  queue_dispose(qp, NULL);
}
/**perform DFS from vertex i*/
void graph_dfs(graph_t *g, int nv, graph_t *n){
 int currTime = 0; graph_t *tmp, *tmp2;int sub_h = 0, max_h = 0;
 int forw = 0, tree = 0, back = 0, cross = 0, height = 0;
 printf("List of edges:\n");
 currTime = graph_dfs_depth(g, nv, n, currTime, &height,&sub_h);
 max_h = height;
 for(tmp = g; tmp != NULL; tmp = tmp->next)
  if(tmp->color == WHITE){
   currTime = graph_dfs_depth(g, nv, tmp, currTime, &height, &sub_h);
   if(max_h < height) max_h = height; ///for disconnected graphs
  }
 printf("List of vertices:\n");
 for(tmp = g; tmp != NULL; tmp = tmp->next){
  tmp2 = tmp->pred;
  printf("%2d: %2d/%2d (%d)\n",tmp->id,tmp->td,tmp->tq,(tmp2!=NULL)? tmp->pred->id : -1);
 }
 printf("\n----------%d\n", max_h);
}
/**perform recursive DFS from vertex i: labels nodes with td/tq, edges as T/F/B/C*/
int graph_dfs_r(graph_t *g, int nv, graph_t *n, int currTime){
 edge_t *e; graph_t *tmp;
 n->color = GREY;
 n->td = ++currTime;
 e = n->head;
 while(e != NULL){
   tmp = e->dst;
   switch(tmp->color){
     case WHITE: printf("%d -> %d : T\n", n->id, tmp->id); break;
     case GREY : printf("%d -> %d : B\n", n->id, tmp->id); break;
     case BLACK: if (n->td < tmp->td)printf("%d -> %d : F\n", n->id, tmp->id);
                 else printf("%d -> %d : C\n", n->id, tmp->id);
   }
   if(tmp->color == WHITE){
     tmp->pred = n;
     currTime = graph_dfs_r(g, nv, tmp, currTime);
   }
   e = e->next;
 }
 n->color = BLACK;
 n->tq = ++currTime;
 return currTime;
}
