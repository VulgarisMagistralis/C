#include<stdio.h>
#include<stdlib.h>

void bin(int*,int,int);
void simple(int,int,int,int*,int*,int*,int*);
int main(void){
 int *a = malloc(5 * sizeof(int)),
 *sol = (int*)malloc(5 * sizeof(int)),
 *mark = (int*)malloc(5 * sizeof(int)),
 count = 0, k = 3, i = 0;
 for(;i<5;i++){
  sol[i] = 0;
  mark[i] = 0;
  a[i] = i*i+4;
 }
 simple(0,5,3,&count,a,sol,mark);
}
void simple(int level, int n, int k, int *count, int *a, int *sol, int *mark){
 int i;
 if(level >= k){
  (*count)++;
  for(i=0;i<k;i++)printf("%d,", sol[i]);
  fprintf(stdout, "\n");
  return;
 }
 for(i=0; i<n; i++){
  if(mark[i] == 0){
   mark[i] = 1;
   sol[level] = a[i];
   simple(level+1, n, k, count, a, sol, mark);
   mark[i] = 0;
  }
 }
}
void bin(int *a, int n, int level){
 int i = 0;
 if(level >= n){
  printf("\n");
  for(;i < n; i++)
   printf("%d ", a[i]);
  return;
 }
 for(i = 0; i < 2; i++){
  a[level] = i;
  bin(a, n, level+1);
 }
}
