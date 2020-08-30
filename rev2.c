#include<stdio.h>
#include<stdlib.h>
typedef struct{
 int no;
 int *choice;
}data;
void multi(int,data*,int,int*,int*);
int main(int argc, char **argv){
 int i, j, n = 4, count = 0,
 *solution = malloc(n * sizeof(int));
 data *d = (data*) malloc(n * sizeof(data));
 for(i = 0; i < n; i++){
  d[i].no = (2 * i) + 2;
  d[i].choice = (int*)malloc(d[i].no * sizeof(int));
 }
 for(i = 0; i < n; i++){
  printf("%d.set: ", i + 1);
  for(j = 0; j < d[i].no; j++){
   d[i].choice[j] = i + j + 2;
   printf(" %d ",d[i].choice[j]);
  }
  printf("\n");
 }
 multi(0, d, n, solution, &count);
 printf("NO: %d\n", count);
}
void multi(int level, data *d, int n, int *sol, int *count){
 if(level >= n){
  (*count)++;
  return;
 }
 int i;
 for(i = 0; i < n; i++){
  sol[level] = d[level].choice[i];
  multi(level+1, d, n, sol, count);
 }
}
