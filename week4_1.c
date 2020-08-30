/** Pointers **/
/*
#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main(int argc, char **argv){

 int n,k,i,j,*ptr1,*ptr2,*arr_ptr;
 int array[DIM] = {1,4,3,7,8,980,78,34};
 n = 7; k = 7; arr_ptr = array;
 ptr1 = &n;
 ptr2 = &k;
 fprintf(stdout,"same address: %s \n", ptr1 == ptr2 ? "YES" : "NO");
 fprintf(stdout,"same value: %s \n", *ptr1 == *ptr2 ? "YES" : "NO");

 fprintf(stdout,"N: %d, its address: %d \n",*ptr1,ptr1);
 /*for(i = 0; i < DIM; i++)*//*
 for(arr_ptr = array; arr_ptr < array + 10; arr_ptr++) // useless but dope
  fprintf(stdout,"Value: %d \n adress: %d \n",*(arr_ptr),(arr_ptr));
 free(ptr1);
 free(ptr2);
 free(arr_ptr);
 return 0;
}
*/

/* Pointer Dynamics

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
 int i,n,*ptr;
 n = atoi(argv[1]);
 ptr = &n;
 ptr = (int*)malloc((*ptr)*sizeof(int));
 for(i=0;i<n;i++){
  fprintf(stdout,"\nEnter %d.element: ",i+1);
  fscanf(stdin,"%d",(ptr+i));
 }
 free(ptr);
 return 0;
}
**/
/** Struct Pointers */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
 int x,y;
 float distance;
}vertex;

int main(int argc, char **argv){
 vertex *ptr;
 int number_node = atoi(argv[1]),i;
 ptr =(vertex*)malloc(number_node * sizeof(vertex));
 if(ptr == NULL) exit(0);
 for(i=0;i<number_node;i++){
  fprintf(stdout,"\nEnter %d.coordinates(x,y) :",i+1);
  fscanf(stdin,"%d %d",(*(ptr+i)).x,(*(ptr+i)).y);
 }
 for(i=0;i<number_node;i++)
  fprintf(stdout,"Coordinates: %d,%d. Distance: %f",(*ptr).x,(*ptr).y,(*ptr).distance);

 return 0;
}
/* Compare + length

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int length(char *string){
 char *p = string;
 while(*p != '\0')p++;
 return p - string;
}
int comparel(char *s1,char *s2){
 while(*s1 == *s2 && *s1 != '\0'){
 s1++;s2++;
 }
 return *s1 - *s2;
}

int main(void){
 char *string1 = "ZFLIPFLOPS";
 char *string2 = "AFUCKFLOPS";
 printf("%d %d\n",length(string1),length(string2));
 printf("%d \n",comparel(string1,string2));
 printf("%d \n",strcmp(string1,string2));
}
*/
