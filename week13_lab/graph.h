#ifndef _GRAPH
#define _GRAPH
#include "limits.h"
#include "util.h"
/* constant declaration */
#define MAX_LINE 100
enum {WHITE, GREY, BLACK};
/* type declarations */
typedef struct edge edge_t;
typedef struct vertex graph_t;
/* list (vertices) of lists (edges): edges */
struct edge{
  int weight;
  struct vertex *dst;
  struct edge *next;
};
/* list (vertices) of lists (edges): vertices */
struct vertex{
  int id, color, scc;
  int td, tq, dist;
  struct vertex *pred;
  struct edge *head;
  struct vertex *next;
};
/* extern function prototypes */
extern graph_t *graph_load(char*, int*);
extern graph_t *graph_find(graph_t*, int, int);
extern void graph_dispose(graph_t*, int);
#endif
