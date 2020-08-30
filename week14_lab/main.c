#include "graph.h"
#include "ver2.h"
#include "queuePublic.h"
int main(int argc, char **argv){
 int choice = 4, nv, v1, v2;
 graph_t *source, *stop, *g = NULL;
 if(argc != 2) fprintf(stderr, "Missing parameter");
 g = graph_load(argv[1], &nv);
 if(g == NULL) fprintf(stderr, "File Error");
 while(choice != 0){
  fprintf(stdout, "\n1-Shortest Path\n2-Euler's Path\n3-Hamilton's Path\n4-Termination.\nEnter your choice: ");
  fscanf(stdin, "%d", &choice);
  switch(choice){
   case 1: wanted(stdin, stdout, &v1, &v2);
           source = graph_find(g, nv, v1);
           stop = graph_find(g, nv, v2);
           graph_dfs(g, nv, source, stop);
           break;
   case 2: break;
   case 3: break;
   case 4: choice = 0; break;
   default: fprintf(stderr, "\nInvalid choice!\n");
  }
 }
 return SUCCESS;
}
