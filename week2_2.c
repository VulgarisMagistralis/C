#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STOP 99
#define MAX 10

/** Classify -input numbers -DONE
int classify(int,int[]);
void print_array(int[]);

int main(int argc, char **argv){
 int x,flag = 0,a[MAX]={0};
 while(!flag){
  fprintf(stdout,"enter number:");
  fscanf(stdin,"%d",&x);
  flag = classify(x,a);
 }
 print_array(a);
 return 0;
}
int classify(int x,int array[]){
 int i,flag = 0;
 if(x == STOP)flag = 1;
 for(i = 1; i <= 10; i++)
  if((x < 10 * i) && x >= ((i-1) * 10)) array[i-1]++;
 return flag;
}
void print_array(int a[]){
 int i = 0;
 for(i = 0; i < MAX; i++)fprintf(stdout,"between %d-%d: %d\n",i*10,(i+1)*10 ,a[i]);
}
**/
/**anagram check - DONE

int to_lower(char);
int main(int argc, char **argv){
 int occurences[26], i, flag = 1;
 for(i = 0; i < 26; i++) occurences[i] = 0;
 if(argc < 3)fprintf(stdout,"invalid input");
 for(i = 0; i < strlen(argv[1]); i++)
  occurences[to_lower(argv[1][i])]++;
 for(i = 0; i < strlen(argv[2]); i++)
  occurences[to_lower(argv[2][i])]--;
 while(flag && i < 26){
  if(occurences[i] != 0) flag = 0;
  i++;
 }
 if(!flag) fprintf(stdout,"Not anagram");
 else fprintf(stdout,"Anagram\n");
return 0;
}
int to_lower(char x){
 int dif = 0;
 if(x >= 'A' && x <= 'Z')
  dif = x - 'A';
 else dif = x - 'a';
 return dif;
}
**/
/** local minimum search -DONE */

void read_matrix(int,int,int[][MAX]);
void find_minimum(int,int,int[][MAX]);
int main(int argc, char **argv){
 int R, C, m[MAX][MAX];
 fprintf(stdout,"Enter R C :");fscanf(stdin,"%d %d",&R,&C);
 read_matrix(R,C,m);
 find_minimum(R,C,m);
return 0;
}
void read_matrix(int r,int c, int m[][MAX]){
 int i,j;
 for(i = 0; i < r; i++){
  for(j = 0; j < c; j++){
   fprintf(stdout,"Enter element %d,%d: ",i,j);
   fscanf(stdin,"%d",&m[i][j]);
  }
 printf("\n");
 }
}
void find_minimum(int r,int c,int m[][MAX]){
 int i,j,rr,cc,flag = 0;
 for(i = 0; i < r; i++){
  for(j = 0; j < c; j++){
   flag = 1;
   for(rr = i-1; rr <= i+1 && flag == 1; rr++){
    for(cc = j-1; cc <= j+1 && flag == 1; cc++){
     if((rr >= 0) && (cc >= 0) && ((i != rr) || (j != cc)) && (rr < r) && (cc < c))
      if(m[i][j] < m[rr][cc]) flag = 1;
      else flag = 0;
    }
   }
   if(flag) fprintf(stdout, "found local min at %d,%d: %d\n", i, j, m[i][j]);
  }
 }
}
**/

/** averaging matrix m1 into m2 -DONE **/
float average(int,int,float[][MAX],int,int);
void read_matrix(int,int,float[][MAX]);
void print_matrix(int,int,float[][MAX]);
int main(int argc,char **argv){
 int i,j,r,c;
 float m1[MAX][MAX],m2[MAX][MAX];
 fprintf(stdout,"enter m1 dimensions R C: ");fscanf(stdin,"%d %d",&r,&c);
 read_matrix(r,c,m1);
 for(i = 0; i < r; i++)
  for(j = 0; j < c; j++)
   m2[i][j] = average(i,j,m1,r,c);
 print_matrix(r,c,m2);
 return 0;
}
void print_matrix(int r,int c, float m[][MAX]){
 int i, j;
 for(i = 0; i < r; i++) for(j = 0; j < c; j++)
   fprintf(stdout,"\nElement [%d][%d]: %6.2f\n",i,j,m[i][j]);
}
void read_matrix(int r,int c,float m[][MAX]){
 int i,j;
 for(i = 0; i < r; i++) for(j = 0; j < c; j++){
   fprintf(stdout,"\nEnter element [%d][%d]: ",i,j);
   fscanf(stdin,"%f",&m[i][j]);
  }
}
float average(int x,int y,float m[][MAX],int r,int c){
 int i,j,count = 0;
 float sum = 0.0;
 for(i = x-1; i <= x+1; i++)
  for(j = y-1; j <= y+1; j++)
   if((i>=0) && (j>=0) && (i<r) && (j<c)){
    sum = sum + m[i][j];
    count++;
   }
 return (sum /((float)count));
}
