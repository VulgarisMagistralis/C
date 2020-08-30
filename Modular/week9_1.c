/*Modules - DONE primarily*/
#include "week9_1.h"
int loopy();

int main(int argc, char **argv){
 int index ,k, array[10],size;
 for(index = 0; index < atoi(argv[1]); index++) k = loopy();
 printf("%d \nBIIITCH: %d %d\n----------------\nPart 2-------\n",k,wanker,cunt);
 read_array(array,&size);
 write_array(array,size);
 return 0;
}
int loopy(){  //siiiiiiiiick
 static int counter = 1;
 counter++;
 return counter;
}
