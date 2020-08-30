/*More recursive probs*/
#include<stdio.h>
#include<stdlib.h>
#define SOMETHING 5
#define SUCCESS 0
#define FAILURE 1

typedef struct{
 int no_cho;
 int *choices;
}level;

level *create(int);
void destroy(level*,int);
void read_choices(char*,level*,int);
int *create_list(int);
int multi(level*,int*,int,int,int);
int main(int argc,char **argv){
 level *values;int *solutions;
 int size = atoi(argv[1]);
 values = create( atoi( argv[1]));
 read_choices(argv[2],values,size);
 solutions = create_list(size);
 int wha = multi(values,solutions,0,size,0);
 printf("%d",wha);
 destroy( values, atoi( argv[1]));
 return SUCCESS;
}
int multi(level *values,int *solutions,int position,int size,int count){
 int i;
 if(position >= size){
  printf("SUCCESS");
  return count+1;
 }else{
  for(i = 0; i < values[position].no_cho; i++){
   solutions[i] = values[i].choices[i];
   count = multi(values,solutions,position+1,size,count);
  }
 return count;
 }
}
void read_choices(char *file_name,level *values,int size){//works
 int i,choices,j;
 FILE *choice_file = fopen(file_name,"r");
 if(choice_file == NULL)fprintf(stderr,"FAIL");
 for(i = 0; i < size; i++){
  fscanf(choice_file,"%d",&choices);
  values[i].choices = create_list(choices);
  for(j = 0; j < choices; j++){
   fscanf(choice_file,"%d",&values[i].choices[j]);
   fprintf(stdout," %d ",values[i].choices[j]);
  }
  values[i].no_cho = choices;
  printf("\n");
 }
 fclose(choice_file);
}
int *create_list(int size){ // works
 int *list =(int*)malloc(size*sizeof(int));
 if(list == NULL) fprintf(stderr,"FAIL$#");
 return list;
}
level *create(int n){//works
 level *noob;
 noob = (level*)malloc(n * sizeof(level));
 if(noob == NULL)fprintf(stderr,"allocation error!");
 return noob;
}
void destroy(level *trash,int can){ //works
 int i;
 for(i = 0; i < can; i++)free(trash[i].choices);
 free(trash);
}
