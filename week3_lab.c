/* exercise 1

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void read_dim(int*,int*);
int check_dim(int,int,int,int);
void read_matrix(float[][MAX],int,int);
void compute_product(float [][MAX],int,float[][MAX],int,int,float[][MAX],int*,int*);
void write_matrix(float[][MAX],int,int,float[][MAX],int,int,float[][MAX],int,int);


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
void write_matrix(int r,int c,float m[][DIM]){
 int i,j;
 for(i=0;i<r;i++){
  for(j=0;j<c;j++) fprintf(stdout,"[%d]",m[i][j]);
  fprintf(stdout,"\n");
 }
}
void read_matrix(int r,int c, float m[][DIM]){
 int i,j;
 for(i=0;i<r;i++){
  for(j=0;j<c;j++){
   fprintf(stdout,"\nenter [%d][%d] element: ",i,j);
   fscanf(stdin,"%d",&m[i][j]);
  }
 }
}
void compute_product(float m1[][DIM],int r1,float m2[][DIM],int r2, float m3[][DIM]){
 int i,j,k;
 for(i=0;i<r2;i++)
  for(j=0;j<r1;j++){
   m3[j][i] = 0;
   for(k=0;k<r2;k++) m3[j][i] += m1[k][i] * m2[i][k];
  }
}

**/
/* exercise 2 - DONE

#include <stdlib.h>
#include <stdio.h>
#define MAX_CHAR 100

int main(int argc, char **argv){
 FILE *fp; char c;
 int v_count[MAX_CHAR],h_count = 0,h_seq = 0, v_seq = 0,i,col = 0;
 if(argc < 2){ fprintf(stdout,"Invalid arguments\n");return -1;}
 fp = fopen(argv[1],"r");for(i = 0; i<MAX_CHAR;i++)v_count[i] = 0;
 if(fp == NULL){ fprintf(stdout,"File not found\n"); return -1;}
 while(fscanf(fp,"%c",&c) != EOF ){
  if(c == 'h' || c == 'H'){
   h_count++;
   if(h_count >= 5) h_seq++;
  }else h_count = 0;
  if(c == 'v' || c == 'V'){
   v_count[col]++;
   if(v_count[col] >= 5) v_seq++;
  }else v_count[col] = 0;
  if(c == '\n') col = 0;
  else col++;
 }
 fprintf(stdout,"Number of v sequence: %d\nNumber of h sequence: %d\n",v_seq,h_seq);
 fclose(fp);
 return 0;
}
*/
/* exercise 3

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 100

int main(int argc, char **argv){
 FILE *fin,*fout;
 char line[MAX_CHAR];
 int inner = 0, flag = 0, outer = 0;
 if(argc < 5){fprintf(stdout,"invalid arguments\n");return-1;}
 fin = fopen(argv[2],"r"); fout = fopen(argv[4],"w");
 if(fin == NULL || fout == NULL){fprintf(stdout,"error in files\n");return-1;}
 while(fgets(line,MAX_CHAR,fin) != NULL){
   if(line[outer] == argv[1][outer]){
    flag = 1;
    for(inner = 1; inner <= strlen(argv[1]) && flag; inner++)
     if(line[outer + inner] == argv[1][outer + inner])flag = 1;
     else flag = 0;
   }
   if(flag){
    fprintf(fout,"%s",argv[3]);
    outer = outer + strlen(argv[1]);
    flag = 0;
   }else{
    fprintf(fout,"%c",line[outer]);
    outer = outer + 1;
   }
  if(outer == MAX_CHAR || line[outer] == '\n') outer = 0;
  }
 fclose(fin);
 fclose(fout);
 return 0;
}
*/
/* Ex 3 with pointers -DONE*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 100
#define SUCCESS 1

int str_length(char*);

int main(int argc, char **argv){
 char *line;
 int i,k,j,length,line_length;
 FILE *fin,*fout;
 if(argc < 5){fprintf(stdout,"Invalid input");exit(-1);}
 line = (char*)malloc((MAX_CHAR + 1) * sizeof(char));
 fin = fopen(argv[2],"r");
 fout = fopen(argv[4],"w");
 if(line == NULL || fin == NULL){fprintf(stdout,"Error in file reading");exit(0);}
 length = str_length(&argv[1][0]);
 while(fgets(line,MAX_CHAR,fin) != NULL){
  line_length = str_length(line);
  i = 0;
  while(i < line_length){
  j = 0;
  while(argv[1][j] == *(line+i+j) && argv[1][j] != '\0') j++;
  if(j == length){
   fprintf(fout,"%s",argv[3]);
   i = i + length;
  }else{
   if(i == 100) fprintf(fout,"%c",'\n');
    fprintf(fout,"%c",*(line + i));
    i++;
   }
  }
 }
 fclose(fin);
 fclose(fout);
 free(line);
 return SUCCESS;
}
int str_length(char *string){
 char *s = string;
 while(*s != '\0') s++;
 return s-string;
}

