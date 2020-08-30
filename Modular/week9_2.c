/*Just testin some stuff*/
#include "week9_1.h"
void write_array(int *array,int size){
 int i;
 for(i = 0; i < size; i++){
  fprintf(stdout,"\nThe damn numbers:\n");
  fprintf(stdout,"%d = [%d] \n",i, array[i]);
 }
 return;
}
void read_array(int *array,int *size){
 int i;
 fprintf(stdout,"Enter the fucking size = ");
 fscanf(stdin,"%d",size);
 for(i = 0; i < *size; i++){
  fprintf(stdout,"Go on shitface: ");
  fscanf(stdin,"%d", &array[i]);
 }
 return;
}
