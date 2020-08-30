/*Ex 1 Magic square - DONE dont try 4
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
void magic_wrap(int);
int check_rows(int**,int);
int check_cols(int**,int);
int check_diag(int**,int);
int check_square(int**,int);
void print_square(int,int**);
void put_number(int,int**,int*,int,int*);
int main(int argc, char **argv){
 magic_wrap(atoi(argv[1]));return 0;
}
void magic_wrap(int n){
 int **square = (int**)malloc(n*sizeof(int));
 int *used = (int*)malloc((n*n)*sizeof(int));
 int i , j, no_sol = 0;
 for(i = 0; i < n; i++){
  square[i]=malloc(n*sizeof(int));
  for(j = 0; j < n; j++){
   square[i][j]=0;used[i+j]=0;
  }
 }
 put_number(n, square, used, 0, &no_sol);
 printf("Number of solutions:%d\n",no_sol);
}
void put_number(int n,int **sol,int *used,int level,int *no_sol){
 if(level == (n * n)){
  if(check_square(sol,n)){
   printf("\nFound one :\n");
   print_square(n,sol);
   (*no_sol)++;
  }
  return;
 }
 int x=(level/n),y=(level%n),i;
 for(i = 1; i <= (n*n); i++){
  if(used[i] == 0){
   sol[x][y] = i; used[i] = 1;
   put_number(n,sol,used,level+1,no_sol);
   used[i] = 0;
  }
 }
}
int check_square(int **square,int size){
 int row_flag,col_flag,diag_flag;
 row_flag = check_rows(square,size);
 col_flag = check_cols(square,size);
 diag_flag = check_diag(square,size);
 if(row_flag&&col_flag&&diag_flag) return 1;
 else return 0;
}
int check_rows(int **square,int size){
 int i,j,count,
 constant = (size*(size * size + 1))/2;
 for(i = 0; i < size; i++){
  count = 0;
  for(j = 0; j < size; j++) count = count + square[i][j];
  if(count != constant) return 0;
 }
 return 1;
}
int check_cols(int **square,int size){
 int i,j,count,constant = (size*(size*size+1))/2;
 for(i = 0; i < size; i++){
  count = 0;
  for(j = 0; j < size; j++) count = count + square[j][i];
  if(count != constant) return 0;
 }
 return 1;
}
int check_diag(int **square,int size){
 int count = 0,i,constant = (size*(size*size +1))/2;
 for(i = 0; i < size; i++) count = count + square[i][i];
 if(count != constant) return 0;
 count = 0;
 for(i = size-1; i >= 0; i--) count = count + square[i][i];
 if(count != constant) return 0;
 return 1;
}
void print_square(int size,int **square){
 int i,j;
 for(i = 0; i < size; i++){
  for(j = 0; j < size; j++)
   printf("%d",square[i][j]);
  fprintf(stdout, "\n");
 }
}
/*EX 2 Gray Code - DONE
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void print_matrix(int,int**);
int **put_matrix(int,int**);
void wrap_gray(int);
void gray(int,int,int**);
int main(int argc,char **argv){
 wrap_gray(atoi(argv[1]));
 return 0;
}
void wrap_gray(int number){
 int **matrix;
 gray(number, 1, matrix);
}
void gray(int number,int level,int **matrix){
 if(level > number){
  print_matrix(level, matrix);
  return;
 }
 int **new_matrix;
 new_matrix = put_matrix(level,matrix);
 level++;
 gray(number, level, new_matrix);
}
int **put_matrix(int level, int **matrix){
 int i,k=5,l=6,j,**new_mat,cols = level,rows;
 rows = (int)pow(2,level);
 new_mat = (int**)malloc(rows * sizeof(int*));
 for(i = 0; i < rows; i++) new_mat[i] = (int*)malloc(cols * sizeof(int));
 if(level == 1){
  new_mat[0][0] = 0;
  new_mat[1][0] = 1;
  return new_mat;
 }
 for(i = 0; i < rows; i++){
  new_mat[i][0] = (i<(rows/2)? 0 : 1);
  for(j = 1; j < cols; j++){
   new_mat[i][j] = (i < (rows / 2) ? matrix[i][j-1]:matrix[rows-1-i][j-1]);
  }
 }
 return new_mat;
}
void print_matrix(int level,int **matrix){ //works
 int i, j, cols = level-1, rows = pow(2, level-1);
 for(i = 0; i < rows; i++){
  for(j = 0; j < cols; j++) fprintf(stdout,"%d ",matrix[i][j]);
  fprintf(stdout,"\n");
 }
}
*/
