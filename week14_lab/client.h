#ifndef CL_HEAD
#define CL_HEAD
#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "queuePublic.h"
#define SUCCESS 1
#define FAILURE 0
typedef struct path path_t;
typedef struct path{
 graph_t *vertex;
 path_t *next;
};
void display(graph_t*, FILE*, int);
void wanted(FILE*,FILE*,int*,int*);
void shortest_path(graph_t*, int);
void print_error(char*, int);
void display_path(path_t*);
path_t *add(path_t*, graph_t*);
path_t *remove_p(path_t*, graph_t*);
int in_list(path_t*, int);
int graph_bfs(graph_t*, int, graph_t*, graph_t*, path_t**);
#endif
