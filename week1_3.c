#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
#define OVERLAP 0
/**
int main(int argc , char *argv[]){
 int i,flag,n,j,count=0;
 int s1[MAX],s2[MAX];
 for(i=0; i<MAX; i++) s1[i]=i*5;
 //for(i=0;i<MAX ;i++){printf("Array s1[%d]= %d ,s2[%d] = %d \n",i,s1[i],i,s2[i]);}
 if(argc != 4)fprintf(stderr,"Wrong number of input");
 //n = atoi(argv[1]);
 /**
 for(i=0;i<n;i++)s1[i] = i*(i+2);
 for(i=0;i<n;i++){j=(int)argv[2][i]-'0'; printf("%d\n",j);s1[i]=j;} // array ???
 **/
 /**
 j=0;i=0;
 while(i<n){
  while(s1[i] == 0){i++;n--;}
  for(j=0;i<=n && j<n;j++,i++) s1[j] = s1[i];
 }
 for(j=0; j<n; j++) fprintf(stdout,"Array s1[%d]= %d \n",j,s1[j]);
 */
 //Sub array search -DONE
 /**
 for(i=0;i<MAX;i++)s1[i] = (int)argv[1][i]-'0';
 for(i=0;i<atoi(argv[2]);i++)s2[i] = (int)argv[3][i]-'0';
 i=0;
 while(i<= MAX - atoi(argv[2])){
  j=0;flag=1;
  while(j < atoi(argv[2]) && flag == 1){
   if(s1[i+j] != s2[j]) flag=0; j++;
  }
  if(flag == 1){
   if(OVERLAP == 0) i = i + atoi(argv[2]);
   else i++;
   count++;
  }
  else i++;
 }
 fprintf(stdout,"%d\n",count);
return 0;
}
**/
/** Binary conversion**/

int main(int argc,char **argv){
 int bit,temp,k; char hex[] ={'A','B','C','D','E','F'};
 fprintf(stdout,"enter number");fscanf(stdin,"%d",&k); temp = k;
 fprintf(stdout,"Binary number from LSB: \n");
 do{
  bit = temp % 2;
  printf("%d ",bit);
  temp = temp / 2;
 }while(temp != 0);
 fprintf(stdout,"\nOctal number from LSB: \n"); temp = k;
 do{
  bit = temp % 8;
  printf("%d ",bit);
  temp = temp / 8;
 }while(temp != 0);
 fprintf(stdout,"\nHexadecimal form from LSB:\n"); temp = k;
 do{
  bit = temp % 16;
  if(bit >= 10) printf("%c ",hex[bit - 10]);
  else printf("%d ", bit);
  temp = temp / 16;
 }while(temp != 0);
printf("\n");
return 0;
}
