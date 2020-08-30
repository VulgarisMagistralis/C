/*Recursions*/
/*Merge sort + Quick sort*/
#include<stdlib.h>
#include<stdio.h>
#define NUMBER 5
#define SUCCESS 0

void swap(int*,int,int);
void quick_wrap(int*,int);
int partition(int*,int,int);
void quick_sort(int*,int,int);
void merge_wrap(int*,int);
void merge_comb(int*,int*,int,int,int);
void merge_sort(int*,int*,int,int);
void read_write_array(int*,int,int);

int main(void){
 int *array;
 array = (int* )malloc(NUMBER * sizeof(int));
 read_write_array(array,NUMBER, 0);
 quick_wrap(array, NUMBER);
 fprintf(stdout,"By quick sort  ");
 read_write_array(array,NUMBER, 1);
 merge_wrap(array, NUMBER);
 fprintf(stdout,"\nBy merge sort");
 read_write_array(array,NUMBER, 1);
 return SUCCESS;
}
void merge_wrap(int *array,int size){
 int left = 0, right = size-1;
 int *temp=(int*)malloc(size * sizeof(int));
 merge_sort(array,temp,left,right);
 return;
}
void merge_sort(int *array,int *temp,int left,int right){
 int middle;
 if(left >= right) return;
 middle = (left+right) /2;
 merge_sort(array,temp,left,middle);
 merge_sort(array,temp,middle+1,right);
 merge_comb(array,temp,left,middle,right);
 return;
}
void merge_comb(int *array,int *temp,int left, int middle, int right){
 int i,j,k;
 for(i=left,j=middle+1,k=1; i<=middle && j<=right;)
  if(array[i] <= array[j]) temp[k++] = array[i++];
  else temp[k] = array[j++];
 while(i <= middle) temp[k++] = array[i++];
 while(j <= right) temp[k++] = array[j++];
 for(k=1; k <= right; k++) array[k] = temp[k];
 return;
}
void quick_wrap(int *array,int number){
 int left = 0;
 int right = number-1;
 quick_sort(array,left,right);
 return;
}
void quick_sort(int *array,int left,int right){
 int pivot;
 if(left > right) return;
 pivot = partition(array,left,right);
 quick_sort(array,left,pivot - 1);
 quick_sort(array,pivot + 1,right);
 return;
}
int partition(int *array,int left,int right){
 int i = left-1,j = right;
 int pivot = array[right];
 while(i < j){
  while(i<= right && array[++i] < pivot);
  while(j >= left && array[--j] >= pivot);
  if(i<j)swap(array,i,j);
 }
 swap(array,i,right);
 return i;
}
void swap(int *array,int i,int j){
 int temp = array[i];
 array[i] = array[j];
 array[j] = temp;
 return;
}
void read_write_array(int *array,int n,int param){
 int i;
 if(param == 0){
  fprintf(stdout,"Enter the list");
  for(i = 0;i < n; ++i){
   fprintf(stdout,"\n%d.element:",i+1);
   fscanf(stdin,"%d",&array[i]);
  }
 }else{
  fprintf(stdout,"\nSorted list:");
  for(i = 0; i < n; ++i)
   fprintf(stdout,"\n%d.Element:%d",i+1,array[i]);
 }
 return;
}

/*
#include<stdio.h>
#include<stdlib.h>

int run_fact(int);
int get_fibo(int);
int run_fact2(int,int);
int main(int argc,char **argv){
 printf("%d\n",run_fact(atoi(argv[1])));
 printf("%d\n",get_fibo(atoi(argv[1])));
 printf("%d\n",run_fact2(atoi(argv[1]),1));
 return 1;
}
int get_fibo(int number){
 if(number == 0||number == 1) return number;
 return (get_fibo(number-2)+get_fibo(number-1));
}
int run_fact(int number){
 if(number == 1) return number;
 return (number * run_fact(number-1));
}
int run_fact2(int number, int multi){// lit
 if(number == 1) return multi;
 return run_fact2(number-1,number*multi);
}
*/
