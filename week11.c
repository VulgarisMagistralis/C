#include<stdio.h>
#include<stdlib.h>
void man(int**,int);
int main(void){
 int *array = NULL;
 int i;
 man(&array, 10);
 for(i=0; i<10; i++)printf("%d -",array[i]);
}
void man(int **a,int size){
 int i,*a1 = (int*)malloc(size*sizeof(int));
 for(i = 0; i < size; i++) *(a1+i) = 6;
 *a = a1;
}
