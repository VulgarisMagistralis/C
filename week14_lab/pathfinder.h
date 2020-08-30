#ifndef PATH_HEADER
#define PATH_HEADER
#define FAILURE 1
#define SUCCESS 0
graph_t *remove_edge(edge_t*, graph_t*);
graph_t *prim(int, graph_t*, int);
graph_t *copy_g(graph_t*, int);
graph_t *add_node(graph_t*,int,int);
void wanted(FILE*, FILE*, int*, int*);
void sho_path(graph_t*, int);
void display(graph_t*,FILE*);
void print_error(char*,int);
edge_t *get_min(graph_t*);
#endif
