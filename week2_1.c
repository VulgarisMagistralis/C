#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DIM 5
#define LINE_LIMIT 40

/**
int main(int argc, char **argv){
 char m1[DIM][DIM] ={ {'*','*','*','*','*'},
		      {'#','#','#','#','#'},
		      {'#','#','#','#','#'},
                      {'*','*','*','*','*'},
                      {'#','#','#','#','#'} };
 char m2[DIM][DIM] = { {'*','*'},
	  	       {'#','#'} };
 char m3[DIM][DIM];
 int i,j,k,n,dim1=5,dim2=2,flag,r,c;
 //matrix mathc + print mathced - DONE
 for(i=0;i < dim1-dim2+1; i++){
  for(j=0;j < dim1-dim2+1; j++){
   flag = 1; //to stop inner for loops
   for(r=0; r < dim2 && flag == 1; r++)
    for(c=0; c < dim2 && flag == 1; c++)
     if(m1[i+r][j+c] != m2[r][c]) flag = 0;
   if(flag == 1)for(r=0; r < dim2; r++)for(c=0; c < dim2; c++)m3[i+r][j+c] = 1; //putting overlapped matrixes on 3rd
  }
 }
 for(i=0;i <dim1;i++){ //printing				must use
  for(j=0;j<dim1;j++) fprintf(stdout,"| %c |",(m3[i][j] == 1) ? m1[i][j] : ' ');
  fprintf(stdout,"\n");
 }
 return 0;
}
**/
//Functions - FAIL
int search(char str1[],char str2[],int from);

int main(int argc, char **argv){

 char sout[LINE_LIMIT * LINE_LIMIT + 1];
 int i,j,k,n,from = 0,to,endflag;
 if(argc != 4){fprintf(stderr,"invalid input\n");exit(0);}
 do{
  to = search(argv[1],argv[2],from);
  if(to < 0){to = strlen(argv[1]);endflag = 1;} //search sends -1 if not found
  for(i = from; i < to; i++){sout[k] = argv[1][i]; k++;} //no match add s1 as it is
  if(endflag == 0){
   for(i=0; i < strlen(argv[3]); i++){sout[k] = argv[3][i]; k++;}// add str 3 because str2 found
  }
  from = to + strlen(argv[2]);//in the original string - s1 - start from the end of matched point
 }while(endflag != 1);
 sout[k] = '\0'; //sout initialized very large to tolerate max lines but we dont need the rest so endit
 return 0;
}

int search(char str1[], char str2[], int from){
 int i = from,j,k,flag;
 while(i <strlen(str1)-strlen(str2)){
  flag = j = 0;
  while(j < strlen(str2) && flag == 0){
   if(str1[i+j] != str2[j])flag = 1;
   j++;
  }
  if(flag == 0)return i;
  i++;
 }
return -1;
}
