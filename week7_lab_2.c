/*ex1*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000+1
#define FAILURE 0
#define SUCCESS 1

typedef struct word_t{
 char *word;
 int frequency;
 struct word_t *next;
}word;
void list(word*);
void decap(char*);
word *read_file(char*);
word *insert_word(char*);
int search_word(char*,word*);
int main(int argc,char **argv){
 word *head;
 head = read_file(argv[1]);
 return SUCCESS;
}
word *read_file(char *file_name){
 FILE *word_file = fopen(file_name,"r");
 char temp_word[MAX],flag = 1;word *head = NULL;
 while(fscanf(word_file,"%s",temp_word) != EOF){
  decap(temp_word);
  if(!search_word(temp_word,head))
   head = insert_word(temp_word);
 }
 //list(head);
 return head;
}
int search_word(char *name,word *head){
 if(head == NULL)return FAILURE;
 while(head != NULL){
  if(strcmp(head->word,name) == 0){
   head->frequency++;
   return SUCCESS;
  }
  head = head->next;
 }
 return FAILURE;
}
word *insert_word(char *name){//works
 word *new_guy;
 new_guy = (word*)malloc(sizeof(word));
 new_guy->word = (char*)malloc((strlen(name)+1)*sizeof(char));
 strcpy(new_guy->word,name);
 new_guy->frequency = 0;
 new_guy->next = NULL;
 return new_guy;
}
void decap(char *word){//works
 int i;
 for(i = 0; word[i] != '\0'; i++)
  if(word[i] >= 'A' && word[i] <= 'Z')
   word[i] = word[i]-('Z'-'z');
}
void list(word *head){//works
 while(head != NULL){
  printf("%s",head->word);
  head = head->next;
 }
}
