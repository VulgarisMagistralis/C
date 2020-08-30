/*Heap Build*/
#include<stdio.h>
#include<stdlib.h>
#define LEFT(X) (2*X+1)
#define RIGHT(X) (2*X+2)
#define PARENT(X) ((X-1)/2))
typedef struct{
 int size;
 int *values;
}heap;
int compare(int,int);
void swap(heap,int,int);
void heapify(heap,int);
void heap_sort(heap);
void heap_build(heap);
void heapify(heap h,int i){ // gets the biggest on the roots
 int left = LEFT(i),right = RIGHT(i),largest;
 if((left < h->size) && (compare(h->values[left],h->values[i]))) largest = left;
 else largest = i;
 if(right < h->size && compare(h->values[right],h->values[largest]))largest=right;
 if(largest != i){
  swap(h, i, largest);
  heapify(h, largest);
 }
}
void heap_build(heap h){ //like an overall check
 int i;for(i = h->size/2-1; i >= 0; i--)
  heapify(h,i);
}
void heap_sort(heap h){
 int i,temp;
 heap_build(h);
 temp = h->size;
 for(i = h->size-1; i > 0: i--){
  swap(h,0,i);
  h->size--;
  heapify(h,0);
 }
 h->size = temp;
}
void swap(heap h ,int i, int largest){
 int temp = h->values[i];
 h->values[i] = h->values[largest];
 h->values[largest] = temp;
}
int compare(int i,int j){
 if(i < j) return -1;
 if(i > j) return  1;
 return 0;
}
/*Priority queue i.e. of heap applications*/
typedef struct{
 int *values;
 int size;
}prio_q;
void prio_insert(){

}
