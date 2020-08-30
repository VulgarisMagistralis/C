/*EX-1 DONE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX (20+1)

typedef struct pff{
 int price;
 char id[6];
 char *name;
 struct pff *next;
}model;
typedef struct nope{
 char *name;
 char id[6];
 model *models;
 struct nope *next;
}manu;
void list_manu(manu*);
void add_model(model*,manu*);
manu *read_manus(char*);
void read_models(char*,manu*);
int main(int argc,char **argv){
 manu *head;
 head = read_manus(argv[1]);
 read_models(argv[2], head);
 list_manu(head);
 return 0;
}
void read_models(char *file_name,manu *head){
 FILE *model_file = fopen(file_name,"r");
 char id[6],name[MAX];model *temp_model; int price;
 while(fscanf(model_file,"%s%s%d",id,name,&price) != EOF){
  temp_model = (model*)malloc(sizeof(model));
  temp_model->name = (char*)malloc((strlen(name)+1)*sizeof(char));
  strcpy(temp_model->name,name);
  temp_model->price = price;
  strcpy(temp_model->id,id);
  temp_model->next = NULL;
  add_model(temp_model,head);
 }
}
void add_model(model *new_m,manu *head){
 while(strcmp(head->id,new_m->id) != 0) head = head->next;
 if(head->models == NULL) head->models = new_m;
 else{
  while(head->models->next != NULL)head->models = head->models->next;
  head->models->next = new_m;
 }
}
manu *read_manus(char *file_name){
 manu *temp,*last=NULL,*head=NULL;
 char id[6],name[MAX];
 FILE *manufacturers = fopen(file_name,"r");
 while(fscanf(manufacturers,"%s %s",name,id)!=EOF){
  temp = (manu* )malloc(sizeof(manu));
  temp->name=(char*)malloc(MAX*sizeof(char));
  strcpy(temp->name,name);
  strcpy(temp->id,id);
  temp->models= NULL;
  temp->next = NULL;
  if(head == NULL){
   head = temp;last = temp;
  }else{
   last->next = temp;last = last->next;
  }
 }
 return head;
}
void list_manu(manu *head){
 while(head != NULL){
  printf("\nManufacturer: %s [%s]",head->name,head->id);
  while(head->models != NULL){
   printf("\nModel: %s %d",head->models->name,head->models->price);
   head->models = head->models->next;
  }
  head = head->next;
 }
 printf("\n");
}
*/
/*EX 2 2 Done
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
void bin_con(int,int*,int*);
void wrap_binary(int);
int main(int argc,char **argv){
 wrap_binary(atoi(argv[1]));
 return 0;
}
void wrap_binary(int number){
 int size = 0,temp, n = number,*bits,i=1;
 while(n > 0){size++; n = n / 2;}
 temp = size;
 bits = (int*)malloc((size) * sizeof(int));
 bin_con(number, bits, &size);
 while(i <= temp) printf("%d\n",bits[i++]);
}
void bin_con(int number,int *bits,int *size){
 bits[*size] = number % 2;
 if(number < 2) return;
 *(size) = *(size) - 1;
 bin_con(number/2,bits,size);
}
*/
/*EX 2 1 DONE
#include<stdio.h>
#include<stdlib.h>
int mult(int,int);
void mult_wrap(int,int);
int main(int argc,char **argv){
 mult_wrap(atoi(argv[1]),atoi(argv[2]));
 return 0;
}
void mult_wrap(int x,int y){
 int result = mult(x,y);
 printf("%d\n", result);
}
int mult(int x, int y){
 if(y == 0 || x == 0)return 0;
 else if(y == 1) return x;
 else return (x + mult(x,y-1));
}
*/
/*EX 2 3 DONE
#include<stdio.h>
#include<stdlib.h>
int find_cat(int);
void wrap_cat(int);
int main(int argc,char **argv){
 wrap_cat(atoi(argv[1]));
 return 0;
}
void wrap_cat(int number){
 int catalan = find_cat(number);
 printf("Number: %d Catalan:%d\n",number,catalan);
}
int find_cat(int number){
 if(number == 0) return 1;
 int i,count = 0,j;
 for(i = 0,j = number-1; j >= 0 && i < number;j--,i++)
  count = count + find_cat(i)*find_cat(j);
 return count;
}
*/
/*EX 2 4
#include<stdio.h>
#include<stdlib.h>

int ifspace(char);
int count_space(char*);
void count_wrap(char*);
int main(int argc,char **argv){
 count_wrap(argv[1]);
 return 0;
}
void count_wrap(char *s){
 int space_count = count_space(s);
 printf("Count:%d\n",space_count);
 return;
}
int count_space(char *s){
 if(*s == '\0') return 0;
 s = s + 1;
 return ((ifspace(*s)? 1:0) + count_space(s)); //siiick
}
int ifspace(char c){
 if(c == ' ') return 1;
 return 0;
}
*/
/*EX 2 5 DONE

#include<stdio.h>
#include<stdlib.h>

void decap(char*);
void wrap_pal(char*);
void if_pal(char*,int);
int main(int argc,char **argv){
 wrap_pal(argv[1]);
 return 0;
}
void wrap_pal(char *s){
 int length = 0;
 decap(s);
 while(s[length] != '\0'){
  if(s[length] > 'z' || s[length] < 'a')
   s[length] = s[length+1];
  length++;
 }
 if_pal(s,length-1);
}
void if_pal(char *string,int length){
 static int i = 0;
 if(i > length){
  printf("YES!");
  return;
 }
 if(string[i] == string[length]) i++;
 else{ printf("FUCK OFF!"); return ;}
 if_pal(string,length-1);
}
void decap(char *s){ //works
 int i;
 for(i=0;s[i]!='\0';i++)
  if(s[i] <= 'Z' && s[i] >= 'A')
   s[i] = s[i] -('A'-'a');
}
*/
/* EX 2 6 DONE
#include<stdio.h>
#include<stdlib.h>

void tri_wrap(int,int,int);
int main(int argc,char **argv){
 tri_wrap(atoi(argv[1]),1,1);
 return 1;
}
void tri_wrap(int size,int level,int count){
 if(level > size) return;
 printf("%d",level);
 if(count == level){
  printf("\n");
  level++;
  count = 0;
 }
 count = count + 1;
 tri_wrap(size,level,count);
}
*/
