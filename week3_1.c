/** Sudoku **/

/** Search linear + binary

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int binary_search(int,int,int,int[]);
int linear_search(int,int,int,int[]);
int main(int argc, char **argv){
 char c;
 int k,array[MAX],position,left,right;
 fpritnf(stdout,"Enter wanted element");
 fscanf(stdin,"%d",&k);
 fprintf(stdout,"Choose searching method [b/l]:");
 fscanf(stdin,"%c%c",&c); // how was this?
 if(c == 'l' || c == 'L') position = linear_search(k,left,right,array);
 else position = binary_search(k,left,right,array);
 if(position < 0) fprintf(stdout,"not found");
 else fprintf(stdout,"Found at %d ",position);
 return 0;
}
int linear_search(int wanted,int left,int right,int array[]){
 while(left <= right) //T(n) = r-l+1+1 ,second 1 is for the last check when i > right
  if(array[i] == wanted) return i;
  else left++;
 return -1;
}
int binary_search(int wanted,int left,int right,int array[]){
 int center;
 while(left <= right){ //T(n) logarithmic ,always n/2 numbers iterating
  center = (int)((left + right)/2);
  if(wanted == array[center])return center;
  if(wanted <= array[center]) right = center - 1;
  else left = center + 1;
 }
 return -1;
}
**/
/** Networking **/

#include <stdio.h>
#include <stdlib.h>
#define METHOD 1

int main(int argc, char **argv){
 //read pairs perhaps from a file
 if(METHOD > 1) quick_find();
 else if(METHOD < 1) quick_union();
 else weighted_find();

}
void quick_find(){ // such inefficiency much wow
 int i,temp,id[MAX];
 for(i = 0; i < n; i++){ //each connection requires travleing by sizeof array
  while(fscanf(stdin,"%d %d",&p,&q) == 2)
   if(id[p] == id[q]) fprintf(stdout,"Already connected");
   else for(temp =id[p],i = 0; i<n; i++)if(temp == id[q]) id[i] = id[p];

 }
void quick_union(){
 int i,j,p,q,temp,id[MAX];
 while(fscanf(stdin,"%d %d", &p,&q) == 2){
  for(i = p; i != id[i]; i = id[i]);//until you find the root
  for(j = q; j != id[j]; j = id[j]);//until you find the root
  if(i == j)//connected => same roots
  else id[i] = j; //id[j] = i, same shit
 }
}
void weighted_find(){ // worst case at size1 == size2, tree height X num_pairs = T(n)
 int i,j,p,q,id[MAX];
 while(fscanf(stdin,"%d %d",&p,&q) == 2){
  for(i = p; i != id[i]; i = id[i]);
  for(j = q; j != id[j]; j = id[j]);
  if(i == j)//connected to same root
  else{
   if(size[i] < size[j]){//checking size to find bigger tree, put small into bigger one for faster accessing
    id[i] = j;
    size[j] = size[j] + size[i];
   }else{
    id[j] = i;
    size[i] = size[i] + size[j];
   }
  }
}

}


