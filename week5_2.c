/* Lists*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_CHAR 20
#define SUCCES 0
#define FAIL -1
// read and put in list
typedef struct irrelevant_name{
 int number;
 char *name;
 char *surname;
 float average;
 struct irrelevant_name *next;
}student;
void test(student*);
int str_len(char*);
void read_file(char*,student*);
void str_copy(char*,char*);
student* add_student(int,char*,char*,float);
int main(int argc,char **argv){
 student *head = NULL;
 if(argc < 1){fprintf(stderr,"wrong input retard");exit(FAIL);}
 read_file(argv[1],head);
 test(head);
 return SUCCES;
}
void test(student *head){
 student *temp = head;
 while(temp->next != NULL){
  fprintf(stdout,"List of numbers: %d\n",temp->number);
  temp = temp->next;
 }
}
void read_file(char *name,student *head){
 FILE *students_file = fopen(name,"r"); float avg; int no;
 char first[MAX_CHAR],last[MAX_CHAR];student *temp,*temp2;
 temp = (student*)malloc(sizeof(student));
 temp2= (student*)malloc(sizeof(student));
 if(students_file == NULL){fprintf(stderr,"file"); exit(FAIL);}
 while(fscanf(students_file,"%d%s%s%f",&no,first,last,&avg) != EOF){
  temp = add_student(no,first,last,avg);
  fprintf(stdout,"%d %s %s %f \n",no,first,last,avg);
  if(head == NULL){
   head = (student*)malloc(sizeof(student));
   head = temp;
  }else{
   temp2 = head;
   while(temp2->next != NULL) temp2 = temp2->next;
   temp2->next = temp;
  }
 }
}
student* add_student(int number,char *name,char *surname,float average){
 student *new_student;
 new_student = (student* )malloc(sizeof(student));
 new_student->name =  (char* )malloc((str_len(name) + 1) * sizeof(char));
 new_student->surname =(char*)malloc((str_len(surname)+1)* sizeof(char));
 new_student->number = number;
 new_student->average = average;
 str_copy(new_student->name,name);
 str_copy(new_student->surname,surname);
 return new_student;
}
void str_copy(char *s1,char *s2){ //works
 int i;
 for(i = 0; s2[i] != '\0'; i++)
  s1[i] = s2[i];
}
int str_len(char *string){ //works
 char *s = string;
 while(*string != '\0')string++;
 return string - s;
}
