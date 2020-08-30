#include <stdio.h>
#include<stdlib.h>

int main(void){
 int a = 9;
 int b = 6;
 int *c;
 c = &b;
 b = a;
 printf("%d %d\n",*c,b);
}
