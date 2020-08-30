#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define DIM 10
/**/
int main(int argc, char *argv[]){

 int i,j,max,end,n,k,array[DIM],asc_arr[DIM];
 //exercise 1 - DONE
 /**/
 for(i = 0; i < DIM; i++){ //read array
  fprintf(stdout,"Enter %d. element: \n",i+1);
  scanf("%d",&array[i]);
 }
 i=0;j=1;max=0;
 while(i <= DIM){
  while(array[i] < array[i+j] && (i+j) < DIM) {
   j++;
  }
  if(j > max) {max = j; end = i + j;}
  ++i;
 }
 printf("longest %d \n",max);
 for(i = 0;i < max; i++) printf("elements : %d ",array[i+end-max]);
 **
 // exercise 2 -DONE
 int n1=0,n2=0,flag=0;n=0;i=0;j=0;k=0;
 fprintf(stdout,"Enter 2 numbers: ");scanf("%d %d",&n1,&n2);
 if(n1 > DIM || n2 > DIM){printf("number too big"); return 1;}
 for(i = 0;i < n1; i++){
  fprintf(stdout,"enter %d . element \n",i+1);
  fscanf(stdin,"%d",&array[i]);
 }
 for(i = 0;i < n1; i++){
  for(j = -n2; j <= n2; j++){
   if(i+j < n1 && i+j >= 0){
    n = n + array[i+j];
    k++;
   }
  }
  asc_arr[i] = (int)(n / k);
 }
for(i = 0; i < n1; i++) printf("\n%d \n", asc_arr[i]);

return 0;
}
**/

//exercise 3 -DONE
/**
int factorial(int);
int get_power(int);
void read_matrix(int[][DIM],int,int);
void print_matrix(int[][DIM],int,int);
int main(int argc, char **argv){
 int R,C,i,j,k,m1[DIM][DIM],m2[DIM][DIM];
 fprintf(stdout,"enter row and col: ");fscanf(stdin,"%d %d", &R,&C);
 if(R > DIM || C > DIM){fprintf(stderr,"big dimensions");exit(0);}
 read_matrix(m1,R,C);
 for(i = 0; i < R;i++){
  for(j = 0; j < C; j++){
   if(m1[i][j] == 0) m2[i][j] = 0;
   else if(m1[i][j] < 0) m2[i][j] = factorial(-m1[i][j]);
   else m2[i][j] = get_power(m1[i][j]);
  }
 }
 print_matrix(m2,R,C);
 return 0;
}
int factorial(int n){
 int i,j = 1;
 for(i = 1; i <= n; i++) j = j * i;
 return j;
}
int get_power(int n){
 int i,j = 10;
 while(j <= n) j = j * 10;
 return j;
}
void print_matrix(int matrix[DIM][DIM],int r,int c){
 int i,j;
 for(i=0;i<r;i++){
  for(j=0;j<c;j++)
   fprintf(stdout,"[%d]",matrix[i][j]);
  printf("\n");
 }
}
void read_matrix(int matrix[DIM][DIM],int r,int c){
 int i,j;
 for(i=0;i<r;i++)for(j=0;j<c;j++)fscanf(stdin,"%d",&matrix[i][j]);
}
**/
 //exercise 4
void print_matrix(int,int,int[][DIM]);
void read_matrix(int,int,int[][DIM]);
void multi_matrix(int[][DIM],int,int[][DIM],int,int[][DIM]);
int main(int argc, char **argv){
 int r1,r2,c1,c2,m1[DIM][DIM],m2[DIM][DIM],m3[DIM][DIM];
 fprintf(stdout,"enter r1 c1 :\n");fscanf(stdin,"%d%d",&r1,&c1);
 fprintf(stdout,"enter r2 c2 :\n");fscanf(stdin,"%d%d",&r2,&c2);
 if(r1> DIM || r2>DIM || c1> DIM || c2>DIM || c1 != r2) fprintf(stdout,"error in input\n");
 read_matrix(r1,c1,m1);
 read_matrix(r2,c2,m2);
 multi_matrix(m1,r1,m2,r2,m3);
 print_matrix(r1,c2,m3);
 return 0;
}
void print_matrix(int r,int c,int m[][DIM]){
 int i,j;
 for(i=0;i<r;i++){
  for(j=0;j<c;j++) fprintf(stdout,"[%d]",m[i][j]);
  fprintf(stdout,"\n");
 }
}
void read_matrix(int r,int c, int m[][DIM]){
 int i,j;
 for(i=0;i<r;i++){
  for(j=0;j<c;j++){
   fprintf(stdout,"\nenter [%d][%d] element: ",i,j);
   fscanf(stdin,"%d",&m[i][j]);
  }
 }
}
void multi_matrix(int m1[][DIM],int r1,int m2[][DIM],int r2, int m3[][DIM]){
 int i,j,k;
 for(i=0;i<r2;i++)
  for(j=0;j<r1;j++){
   m3[j][i] = 0;
   for(k=0;k<r2;k++) m3[j][i] += m1[k][i] * m2[i][k];
  }
}


