#ifndef _PATH2
#define _PATH2
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "queuePublic.h"
#define SUCCESS 0
#define FAILURE 1
typedef struct sol solution;
typedef struct sol{
 int total_weight;
 graph_t *head;
 struct sol *next;
 int id;
};
edge_t *get_min(graph_t*);
graph_t *remove_list(graph_t*, graph_t*);
graph_t **add_list(graph_t*, graph_t**);
void graph_dfs(graph_t*, int, graph_t*, graph_t*);
int graph_dfs_r(graph_t*, int, graph_t*, graph_t*, int*, solution*, int, graph_t**);
void graph_reset(graph_t *g);
void add_sol(solution*, graph_t*, int);
void wanted(FILE*, FILE*, int*, int*);
#endif
