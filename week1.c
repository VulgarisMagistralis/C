#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MY_CONSTANT 120

int main (void){
	int number = 0;
	{ //Interface
	typedef int dik;
	dik n = 0;
	printf("at least it works\n");
	printf("Lets get interactive\n enter a number  please...");
	scanf("%d",&n);
	number = n;
	printf("number was: %d \n",n);
	}
	{//Exercise
		bool jump = false; int i,j;
		for(i=0; i<number+1 ; i++) printf(" _");//top frame
		printf("\n");i = 1;
		while(i <= number){
			if(!jump){printf("|");for(j=0;j<number;j++)printf("# ");printf("|\n"); jump = true;i++;}//odd rows
			else {printf("|");for(j=0;j<number;j++)printf(" #");printf("|\n"); jump = false;i++;}//even rows
		}
		for(i=0; i<number+1 ;i++) printf(" _");//bottom frame
	}
	return 0;
}
