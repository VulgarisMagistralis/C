/* EX-1 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000+1
#define FAILURE -1
#define SUCCESS  1
#define INSERT_METHOD "Head" //insertion methods = {Head,Tail,Ordered}
typedef struct word_t{
 char *word;
 int frequency;
 struct word_t *next;
}word;
void decap(char*);
word *read_file(char*);
int check_list(char*,word*);
word *new_element(char, char*);
void write_file(word*,char*);
void increase_frequency(word*,char*);
void insert_word(word*,word*,char*,char*);
int main(int argc, char **argv){
 word *word_list;
 word_list = read_file(argv[1]);
 //write_file(word_list, argv[2]);
 return SUCCESS;
}
word *read_file(char *file_name){
 char temp_word[MAX]; word *head;
 FILE *file_in = fopen(file_name, "r");
 while(fscanf(file_in, "%s", temp_word) != EOF){
  decap(temp_word);
  if(!check_list(temp_word, head))
   ;//insert_word(head,tail,INSERT_METHOD,temp_word);
 }
 return head;
}
void write_file(word *head,char *filename){
 FILE *word_file = fopen(filename,"r");
 while(head != NULL){
  fprintf(stdout,"%s: %d",head->word,head->frequency);
  head->next;
 }
}
void insert_word(word *head,word *tail,char *command,char *string){
 word *new_word,*t1,*t2;
 if(strcmp(command,"Head") == 0){//simple enough
  if(head == NULL) head = new_element(0,string);
  else{
   new_word = new_element(0,string);// 0 for initializing values
   new_word->next = head;
   head = new_word;
  }
  return; //head -> first element
/* }else if(strcmp(command,"Tail") == 0){//this ll do i guess
  if(tail == NULL || head == NULL){
   tail = new_element(0,string);
   head = tail;
  }
  new_word->next = tail->next;
  tail->next = new_word;
  return;
 }else if(strcmp(command,"Ordered") == 0){
  if(head == NULL ||strcmp(string,head->word) > 0){ //first element assignment
   new_word = new_element(0,string);
   new_word->next = head;
   head = new_word;
   return;
  }else{
   t1 = new_element(1,"");
   t2 = new_element(1,"");
   t1 = head; t2 = head->next;
   while((t1 != NULL) && (strcmp(string,t2->word) < 0)){
    t1 = t2; t2 = t2->next;
   }
   new_word->next = t2;
   t1->next = new_word;
   return;
  }*/
 }else fprintf(stderr,"Unrecognized Command!");
 free(new_word);
 return;
}
int check_list(char *word_search, word *head){
 if(head == NULL) return 0;
 word *temp = head;
 while(temp != NULL){
  if(strcmp(temp->word, word_search) == 0){
   (temp->frequency)++;
   return 1;
  }
  temp = temp->next;
 }
 return 0;
}
void decap(char *word){
 int i;
 for(i = 0; word[i] != '\0'; i++)
  if(word[i] >= 'A' && word[i] <= 'Z')
   word[i] = word[i]-('Z'-'z');
}
word *new_element(char temp, char *string){
 word *head = (word*)malloc(sizeof(word));
 if(head == NULL) exit(FAILURE);
 head->word = strdup(string);
 head->frequency = 0;
 head->next = NULL;
 return head;
}

/*EX - 2 -DONE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 50+1
#define MAX_ID 16+1
#define SUCCESS 0
#define FAILURE 1
typedef struct{ int day; int month;int year;}date;
typedef struct guy{
 char *name;
 char id[MAX_ID];
 int salary;
 date entry_date;
 struct guy *next;
 struct guy *prev;
}employee;
void str_copy(char*,char*);
void print_list(employee*);
employee *read_file(char*);
employee *new_element(int,int);
employee *search(employee*,char*);
void move(employee*,char*);

int main(int argc,char **argv){
 employee *head,*wanted;
 head = read_file(argv[1]);
 wanted = search(head,argv[2]);
 move(wanted,argv[3]);
 return SUCCESS;
}
void move(employee *wanted,char *command){//works
 int i = 0;
 print_list(wanted);
 while(command[i] != '\0'){
  if(command[i] =='-')
   if(wanted->next != NULL)  wanted = wanted->next;
  else
   if(wanted->prev != NULL)  wanted = wanted->prev;
  print_list(wanted);
  i++;
 }
}
employee *search(employee *head,char *name){//works
 while(strcmp(name,head->name) != 0)head = head->prev;return head;
}
employee *read_file(char *name){//works
 employee *temp,*head,*prev;FILE *file_in;
 int temp_salary, day, year, month,flag=1;
 char temp_id[MAX_ID],temp_name[MAX_NAME];
 file_in = fopen(name,"r");
 prev = new_element(0,0);
 head = new_element(0,0);
 while(fscanf(file_in,"%s %s %d.%d.%d %d",temp_name,temp_id,&day,&month,&year,&temp_salary) != EOF){
   temp = new_element(strlen(temp_name),1);
   str_copy(temp->name,temp_name);
   str_copy(temp->id,temp_id);
   temp->salary = temp_salary;
   temp->entry_date.day = day;
   temp->entry_date.year = year;
   temp->entry_date.month = month;
   head = temp;
   if(flag){ //first element
    prev = temp;
    temp->prev = NULL;//ENDING CONDITION for list
    temp->next = NULL;
    flag = 0;
   }else{
    temp->prev = prev;
    temp->prev->next = temp;
    prev = temp;
   }
 }
 return head;
}
employee *new_element(int length,int param){//works
 employee *element; element = (employee*)malloc(sizeof(employee));
 if(element == NULL){fprintf(stderr,"FAILED allocation");exit(FAILURE);}
 if(param) element->name = (char*)malloc((length+1) * sizeof(char));
 return element;
}
void print_list(employee *head){//works
 fprintf(stdout,"%s. ID: %s. %d. %d.%d.%d\n",
 head->name,
 head->id,
 head->salary,
 head->entry_date.day,
 head->entry_date.month,
 head->entry_date.year);
 head = head->prev;
}
void str_copy(char *s1,char *s2){//works
 int i;for(i=0;s2[i] !='\0';i++) s1[i] = s2[i];s1[i] = '\0';
}
*/
