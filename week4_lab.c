/** Exercise 1 FAIL **

#include <stdio.h>
#include <stdlib.h>
#define LINE_LIM 100
#define WORD_LIM 20

void read_words(char*,char***,int*);
int length(char*);
int main(int argc, char *argv[]){
 int i,j,k,n;
 FILE *fin;
 char **words = 0;
 read_words(argv[2],&words,&n);
 return 0;
}
void read_words(char *name,char ***words,int *n){
 FILE *fin;
 fin = fopen(name,"r");
 *n = 0;
 char word[WORD_LIM];
 int length_word,i;
 if(fin == NULL)exit(0);
 while(fscanf(fin,"%*s",word) != EOF)(*n)++;
 *words = (char**)malloc(*n *sizeof(char*));
 fclose(fin);
 if(*words == NULL)exit(0);
 fin = fopen(name,"r");
 i = 0;
 while(fscanf(fin,"%s",word) != EOF){
  length_word = length(word);
  words[i] = (char*)malloc(length_word * sizeof(char));
  if(*words[i] == NULL)exit(0);
  *words[i] = word;
  fprintf(stdout,"%s",*words[i]);
  i++;
 }

 fclose(fin);
}
int length(char *word){
 char *p = word;
 while(*p != '\0')p++;
 return p - word;
}
*/
/** EX 1 without pointers -DONE

#include <stdio.h>
#include <stdlib.h>
#define LINE_LIM (100 +1)
#define WORD_LIM (20 + 1)
#define FAIL -1

int exists(char*,char[][WORD_LIM],int,int);
int compare(char*,char*);
void read_text(char*,char[][WORD_LIM],int);
int read_words(char*, char[][WORD_LIM]);
void display_result(char[][WORD_LIM],int[LINE_LIM],int);

int main(int argc, char **argv){
 int i,j,k,n;
 char words[LINE_LIM][WORD_LIM];
 FILE *fin;
 n = read_words(argv[1],words);
 read_text(argv[2],words,n);
 return 0;
}
void read_text(char *name,char words[][WORD_LIM],int n){
 FILE *fin = fopen(name,"r");
 int i,position=0,j,times[LINE_LIM];
 char temp[WORD_LIM];
 for(i = 0; i < n; i++) times[i] = 0;
 if(fin == NULL)exit(0);
 while (fscanf(fin,"%s",temp) != EOF){
  position = exists(temp,words,n,1);
  if(position > -1)
   times[position] = times[position] + 1;
 }
 fclose(fin);
 display_result(words,times,n);
}
void display_result(char words[][WORD_LIM],int times[LINE_LIM],int n){
 int i;
 for(i =0;i<n; i++)fprintf(stdout,"Word: %s used %d times.\n",words[i],times[i]);
}
int read_words(char *name,char words[][WORD_LIM]){
 int i,k,n = 0,j = 0;
 char temp[WORD_LIM];
 FILE *fin = fopen(name,"r");
 if(fin == NULL)exit(FAIL);
 while(fscanf(fin,"%*s") != EOF) n++;
 fclose(fin); fin = fopen(name,"r");
 for(i = 0; i < n; i++){   //avoiding duplicate words
  fscanf(fin,"%s",temp);
  if(!exists(temp,words,n,0)){
   k = 0;
   while(*(temp+k) != '\0'){
    *(*(words+j)+k) = *(temp+k);
    k++;
   }
   *(*(words+j)+k) = '\0';
  }
  j++;
  printf("Input: %s\n",*(words+i));
 }
 fclose(fin);
 printf("Number of words: %d\n",n);
 return j;
}
//for param 1 returns position,for param 0 check only existance
int exists(char word[],char words[][WORD_LIM],int n,int param){
 int i;
 for(i = 0; i < n; i++){
  if(compare(word,words[i]) == 0){
   if(param == 0) return 1;
   if(param == 1) return i;
  }
 }
  if(param == 0) return 0;
  if(param == 1) return -1;
}
int compare(char *s1,char *s2){
 while(*s1 == *s2 && *s1 != '\0'){
  s1++;s2++;
 }
 return *s1 - *s2;
}
*/
/* ex2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define CODE 4+1
typedef struct{
 char *code;
 float x1, y1;
 float x2, y2;
 float area;
 float peri;
}rect;
int compare(char*,char*);
void find_peri(rect*,int);
//void find_area(rect*,int);
//void sort_area(rect*,int,int);
int search(rect*,char*,int);
void read_vertices(char*,rect*,int*);
//void print_results(char*,char*,rect*,int);

int main(int argc,char **argv){
 if(argc < 3)exit(0);
 rect *rects;int n;
 read_vertices(argv[1],rects,&n);/*
 find_area(rects,n);
 find_peri(rects,n);
 print_results(argv[2],argv[3],rects,n);*/
 return 0;
}/*
void sort_area(rect *rects,int n ,int param){
 int i,j;rect temp;
  for(i = 0; i < n - 1; i++){
   for(j = i + 1; j < n; j++){
    if(param == 0){
     if(rects[i].area < rects[j].area){
      temp = rects[i];
      rects[i] = rects[j];
      rects[j] = temp;
     }
    }
    if(param == 1){
     if(rects[i].peri < rects[j].peri){
      temp = rects[i];
      rects[i] = rects[j];
      rects[j] = temp;
     }
    }
  }
 }
}
void print_results(char *afile,char *pfile,rect *rects,int n){
 FILE *farea = fopen(afile,"w");
 FILE *fperi = fopen(pfile,"w");
 sort_area(rects,n,0); int i;
 for(i=0;i<n;i++)fprintf(farea,"\nRectangle: %s ,area: %f",rects[i].code,rects[i].area);
 fclose(farea); sort_area(rects,n,1);
 for(i=0;i<n;i++)fprintf(fperi,"\nRectangle: %s ,perimeter: %f",rects[i].code,rects[i].peri);
}
void find_peri(rect *rects,int n){
 int i;float peri1=0.0,peri2=0.0;
 for(i = 0; i < n; i++){
  if(rects[i].peri == 0.0){
   peri1 = rects[i].x1-rects[i].x2;
   if(peri1 < 0) peri1 = - peri1;
   peri2 = rects[i].y1-rects[i].y2;
   if(peri2 < 0) peri2 = - peri2;
   rects[i].peri=2*(peri1+peri2);
  }
 }
}
void find_area(rect *rects,int n){
 int i;float area = 0.0;
 for(i = 0; i < n; i++){
  if(rects[i].area == 0.0){
   area = rects[i].x1 - rects[i].x2;
   area = area*(rects[i].y1-rects[i].y2);
   if(area < 0) area = - area;
   rects[i].area = area;
  }
 }
}*/
void read_vertices(char *name,rect *rects,int *n){
 FILE *fin = fopen(name,"r");float x,y;int i;
 char *code=(char*)malloc(CODE*sizeof(char));
 int position = 0,count = 0;
 if(fin == NULL) exit(0);
 fscanf(fin,"%d",n); *n = (int)((*n)/2);
 rects = (rect*)malloc((*n)*sizeof(rect));
 for(i=0;i<*n;i++) (rects+i)->code=(char*)malloc(sizeof(char)*CODE);
 if(rects == NULL) exit(0);
 while(fscanf(fin,"%s %f %f",code,&x,&y) != EOF ){
  position = search(rects,code,*n);
  //printf("%d",position);
  if(position >= 0){
   (rects+position)->x2 = x;
   (rects+position)->y2 = y;
  }else{
   (rects+count)->code =code;
   (rects+count)->x1 = x;
   (rects+count)->y1 = y;
   count++;
  }
 }
// if(count-1 != *n)fprintf(stderr,"Problem in file data\n");
 fclose(fin);
}
int search(rect *rects,char *code,int n){
 int i;
 for(i = 0; i < n; i++){
  printf("%d\n",compare((rects + i)->code,code));// == 0)
  printf("%d\n",strcmp((rects+i)->code,code));
  printf("in :%s st: %s\n",code,(rects+i)->code);
   return i;
 }
}
int compare(char *s1,char *s2){
 while(*s1 == *s2 && *s1 != '\0'){
  s1++;s2++;
 }
 return *s1 -*s2;
}
