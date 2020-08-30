#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define EXIT_SUCCESS 1
//#define EXIT_FAILURE 0

int main(int argc, char *argv[]){

 //variables
 int row,col,i,n,mid,j,bit,bits[5]={1,0,0,1,1},nb=0;
 //printf("Command Line:");
 //for(i=0;i<argc;i++) printf("%s \n",argv[i]);
 /*if(argc == 1) {fprintf(stdout,"entered correctly \n"); return EXIT_SUCCESS;}
 else {fprintf(stderr,"entered wrong prick \n"); return EXIT_FAILURE;}*/
 //Diamond - DONE
 /***
 printf("Enter the number for Scale \t");
 scanf("%d",&n); if(n%2 == 0) {printf("Must be an odd number wanker!"); return EXIT_FAILURE;}
 mid=(int) (n-1)/2;
 for(row = 0;row < n; row++){
  for(col = 0 ;col < n; col++){
   if(row <= mid){ // check if fails
    if((col == mid-row)||(col == mid+row))printf("+");
    else printf("-");
   }else{
     if(col == mid-(n-row-1)||col==mid+(n-row-1))printf("+");
     else printf("-");
    }
  }printf("\n");
 }
****/
//Bit-o-meter - DONE
 printf("Enter the damn number");scanf("%d",&n);i = 0;
 while(n != 0){
  bit =(int) n % 2; bits[i] = bit;
  printf("%d %d\n",n,bit);
  n = n / 2;++i;
 }
 printf("\n");
//Flippin Floyd - DONE
/**
printf("whats up \n");scanf("%d",&n);if(n<0)n*(-1);
printf("first: %s \n",argv[1]);printf("input: %d \n", n);
bit=0;i=0;row=0;
do{
 for(i=0;i <= row;i++){
  printf("%d",++bit);
 }printf("\n");row++;
}while(row < n);
**/
//SQUARE - DONE
/**
printf("Enter the damn number:\t");scanf("%d",&n);
for(row=0;row<n;row++){
 for(j=0;j<n;j++)
  if(row%2 == 0)printf("%d",(n*row)+1+j);
  else printf("%d",n*(row+1)-j);
 printf("\n");
}

**/
return 0;
}
