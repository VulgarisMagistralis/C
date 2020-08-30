#include "graph.h"
/* static function prototypes */
static graph_t *new_node(graph_t *, int);
static void new_edge(graph_t *nodes, int nv, int i, int j, int weight);
/**load a graph from file: adjacency lists*/
graph_t *graph_load(char *filename, int *nv){
 graph_t *g = NULL;
 char line[MAX_LINE];
 int i, j, weight, dir;
 FILE *fp;
 fp = util_fopen(filename, "r");
 fgets(line, MAX_LINE, fp);
 if(sscanf(line, "%d%d", nv, &dir) != 2){
   sscanf(line, "%d", nv);
   dir = 1;
 }
 /* create initial structure for vertices */
 for (i = *nv-1; i >= 0; i--)g = new_node(g, i);
 /* load edges */
 while(fgets(line, MAX_LINE, fp) != NULL){
   if(sscanf(line, "%d%d%d", &i, &j, &weight) != 3){
     sscanf(line, "%d%d", &i, &j);
     weight = 1;
   }
   new_edge(g, *nv, i, j, weight);
   if(dir == 0) new_edge(g, *nv, j, i, weight);
 }
 fclose(fp);
 return g;
}
/*find the vertex element with a given id*/
graph_t *graph_find(graph_t *g, int nv, int id){
  graph_t *n = g;
  while(n != NULL) {
    if(n->id == id) return n;
    n = n->next;
  }
  return NULL;
}
/*quit the memory associated to a graph*/
void graph_dispose(graph_t *g, int nv){
  graph_t *n;
  edge_t *e;
  while (g != NULL) {
    n = g;
    while (n->head != NULL) {
      e = n->head;
      n->head = e->next;
      free(e);
    }
    g = n->next;
    free(n);
  }
}
/*initialize the list element for a new vertex*/
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
/*insert a new edge in the graph*/
static void new_edge(graph_t *g, int nv, int i, int j, int weight){
  graph_t *src, *dst;
  edge_t *e;
  src = graph_find(g, nv, i);
  dst = graph_find(g, nv, j);
  e = (edge_t *)util_malloc(sizeof(edge_t));
  e->dst = dst;
  e->weight = weight;
  e->next = src->head;
  src->head = e;
}
