/** Sorting + Searching algortihms **/

#include <stdlib.h>
#include <stdio.h>
#define ALG 4
#define MAX 5

int linear_search(int[],int);
int binary_search(int,int,int[],int);
void insertion_sort(int,int[]);
void selection_sort(int,int[]);
void shell_sort(int,int[]);
void bubble_sort(int,int[]);
void counting_sort(int,int[],int);

int main(int argc, char **argv){
 int n = 5, array[5]={3,4,7,5,2};
 int wanted = 2,left = 0,right = n;
 if(ALG == 0)insertion_sort(array,n);
 if(ALG == 1)selection_sort(n,array);
 if(ALG == 2)counting_sort(wanted,array,n);
 if(ALG == 3)shell_sort(n,array);
 if(ALG == 4)bubble_sort(n,array);
 if(ALG == 5)linear_search(array,wanted);
 if(ALG == 6)binary_search(left,right,array,wanted);

return 0;
}
int linear_search(int array[],int k){
 int i;
 for(i = 0; i < (int)*sizeof(array); i++)
  if(array[i] == k) return i;
 return -1;
}
int binary_search(int left, int right, int array[], int k){
 int l = left, r = right,
 while(l <= r){
  c = (int)((l + r) /2);
  if(array[c] == k) return c;
  else if(array[c] > k)l = c - 1;
  else r = c + 1;
 }
 return -1;
}
void insertion_sort(int n,int array[]){
 int i,j,temp;
 for(i = 1; i < n; i++){
  temp = array[i];
  j = i - 1;
  while(j >= 0 && array[j] > temp){
   array[j+1] = array[j];
   j--;
  }
  array[j + 1] = temp;
 }
}
void selection_sort(int n, int array[]){
 int i,j,temp,min;
 for(i = 0; i < n-1; i++){
  min = i;
  for(j = i+1; j < n; j++){
   if(array[j] <= array[min])min = j;
  }
  temp = array[i];
  array[i] = array[min];
  array[min] = temp;
 }
}
void bubble_sort(int n,int array[]){
 int i,j,flag = 1,temp;
 for(i = 0; i< n && flag == 1; i++){
  flag = 0;
  for(j = 0; j < n-1; j++){
   if(array[j] > array[j+1]){
    temp = array[j];
    array[j] = array[j+1];
    array[j+1] = temp;
    flag = 1;
   }
  }
 }
}
void shell_sort(int n,int array[]){
 int i,j,temp,jump = 1;
 while(jump < (int)(n/3)){
  jump = (jump * 3) + 1;
  while(jump >= 1){
   for(i = jump; i < n; i++){
    j = i;
    temp = array[i];
    while(j>=jump && temp <array[j-jump]){
     array[j] = array[j-jump];
     j-=jump;
    }
    array[j] = temp;
    }
    jump = (int)(jump / 3);
   }
 }
}
void counting_sort(int k,int array[],int n){
 int i,j,c[MAX],b[MAX];
 for(i = 0; i < MAX; i++) c[i] = 0;
 for(i = 0; i < n; i++) c[array[i]]++;
 for(i = 1; i < k; i++) c[i]=c[i]+c[i-1];
 for(i=n-1;i>=0; i++){
  b[c[array[i]]-1] = array[i];
  c[array[i]]--;
 }
 for(i=0;i<n;i++) array[i] = b[i];
}
