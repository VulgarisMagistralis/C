/* EX - 1  FUCK THIS */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LIM (100 +1)
#define WORD_LIM (20 + 1)
#define FAIL -1
typedef struct{
 char *word;
 int frequency;
}word_set;
int exists2(char*,word_set*,int,int);
int compare(char*,char*);
void read_text2(char*,word_set*,int);
void read_words2(char*,word_set*,int*);
void display_result2(word_set*,int*,int);
int main(int argc, char **argv){
 word_set *word_sets; int n;
 read_words2(argv[1],word_sets,&n);
 read_text2(argv[2],word_sets,n);
 return 0;
}
void read_text2(char *name,word_set* word_sets,int n){
 char temp[WORD_LIM];int i,j,position = 0,times[LINE_LIM];FILE *text_file = fopen(name,"r");
 if(text_file == NULL){fprintf(stderr,"text file error");exit(FAIL);}
 for(i = 0; i < n; i++) times[i] = 0;
 while(fscanf(text_file,"%s",temp) != EOF){
  position = exists2(temp,word_sets,n,1);
  if(position > -1) times[position]++;
 }
 fclose(text_file);
 display_result2(word_sets,&times[0],n);
}
void display_result2(word_set *word_sets,int *times,int n){
 int index;
 for(index = 0; index < n; index++)
  fprintf(stdout,"Word: %s ,used %d times\n",word_sets[index],times[index]);
}
void read_words2(char *name, word_set *word_sets,int *num){
 int i,n,j,k,file_lines = 0;
 char temp[WORD_LIM];FILE *word_file = fopen(name,"r");
 if(word_file == NULL){fprintf(stderr,"file not opened!");exit(FAIL);}
 while(fscanf(word_file,"%*s",temp) != EOF) file_lines++;
 fclose(word_file); word_file = fopen(name,"r");
 word_sets = (word_set* )malloc(file_lines * sizeof(word_set));
 if(word_sets == NULL){fprintf(stdout,"allocation error");exit(FAIL);}
 for(i = 0; i < file_lines; i++){
  word_sets[i].word = (char* )malloc(WORD_LIM * sizeof(char));
  if(word_sets[i].word == NULL){fprintf(stderr,"Not allocated");exit(FAIL);}
 }
 j = 0;
 for(i = 0; i < file_lines; i++){
  fscanf(word_file,"%s",temp);
  if(!exists2(temp,word_sets,i,0)){
   j++;
   for(k = 0; temp[k] != '\0'; k++){
    word_sets[j].word[k] = temp[k];
    if(temp[k+1] == '\0') word_sets[j].word[k+1]='\0';
   }
  }
 }
 fprintf(stdout,"Words number: %d", j);
 fclose(word_file);
 *num = j;
}
int exists2(char *word1,word_set *sets,int n,int param){
 int i;
 for(i = 0; i < n; i++){
  if(compare(word1,sets[i].word) == 0){
   if(param == 0) return 1;
   if(param == 1) return i;
  }
 }
 if(param == 0)return 0;
 if(param == 1)return-1;
}
int compare(char *s1,char *s2){
 while(*s1 == *s2 && *s1 != '\0'){
  s1++;s2++;
 }
 return *s1 - *s2;
}
*/
/* EX - 2*/

