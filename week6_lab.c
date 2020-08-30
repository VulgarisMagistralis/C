/*EX-1 DONE - FUCKING FINALLY
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CHAR (30 + 1)
#define FAIL -1
#define COMM (10+1)
#define SUCCESS 0
#define COMM_COUNT 4
typedef struct{
 char name[MAX_CHAR];
 int id,lap_no;
 float *laps;
}cyclist;
cyclist *read_file(char*,int*);
void str_copy(char*,char*);
int str_comp( char*,char*);
int str_len(char*);
float get_avg(cyclist);
void find_best(cyclist*,int);
void print_cyclist(cyclist);
void run_loop(cyclist*,int);
void print_all(cyclist*,int);
void find_cyclist(cyclist*,int,char*);
int main(int argc,char **argv){//works
 cyclist *cyclists;int cyc_no;
 if(argc != 2)exit(FAIL);
 cyclists = read_file(argv[1],&cyc_no);
 run_loop(cyclists,cyc_no);
 return FAIL;
}
void run_loop(cyclist *list,int number){//works
 char line[MAX_CHAR],param[MAX_CHAR],command[MAX_CHAR],commands[COMM_COUNT][COMM] = {{'l','i','s','t','\0'},{'b','e','s','t','\0'},{'d','e','t','a','i','l','s','\0'},{'s','t','o','p','\0'}};
 int i,param_flag,param_index,end;
 fprintf(stdout,"Commands:\n1-list\n2-best\n3-details <name>\n4-stop\n");
 while(1){
  fprintf(stdout,"\nEnter a command:\n");fgets(line,MAX_CHAR,stdin);
  param_flag = 0; end = 0;
  for(i = 0; i < str_len(line)&& !end; i++){
   if(line[i] != ' '&& line[i] != '\n' && !param_flag){command[i] = line[i];command[i+1] = '\0';}
   if(line[i] == '\n' || line[i] == '\0') end = 1;
   if(param_flag && !end){param[param_index] = line[i];param_index++;}
   if(line[i] == ' ' && !end){param_flag = 1;param_index= 0;}
  }
  param[param_index] = '\0';
  if(str_comp(command,commands[3]) == 0) exit(SUCCESS);
  if(str_comp(command,commands[0]) == 0) print_all(list,number);
  if(str_comp(command,commands[1]) == 0) find_best(list,number);
  if(str_comp(command,commands[2]) == 0) find_cyclist(list,number,param);
 }
}
void find_cyclist(cyclist *list,int n,char *name){//works
 int i;for(i = 0; i < n; i++)if(strcmp(list[i].name,name) == 0)print_cyclist(list[i]);
}
void find_best(cyclist *list,int number){//works
 int i,j; float min = 0.0,lap_avg;
 for(i = 0; i < number; i++){
  lap_avg = get_avg(list[i]);
  if(min == 0 || min > lap_avg){min = lap_avg; j = i;}
 }
 print_cyclist(list[j]);
 printf("Average time: %1.2f \n",min);
}
float get_avg(cyclist c){ //works
 int i; float avg = 0.0;
 for(i = 0; i < c.lap_no; i++)avg = avg + c.laps[i];
 avg = avg / (c.lap_no);
 return avg;
}
void print_all(cyclist *list,int number){//works
 int i;for(i = 0; i < number; i++)print_cyclist(list[i]);
}
void print_cyclist(cyclist homo){ //works
 int i;fprintf(stdout,"Cyclist: %s [ID: %d]\n Number of Laps: %d\n",homo.name,homo.id,homo.lap_no);
 for(i = 0; i < homo.lap_no; i++) fprintf(stdout,"%d- %1.2f\n",(i + 1), homo.laps[i]);
}
cyclist *read_file(char *file_name,int *number){ //works
 cyclist *cyclists;
 int total_cyc,lap_no,j,i,id;
 char name[MAX_CHAR];
 FILE *cyclist_data; int cyc_no = 0;
 cyclist_data = fopen(file_name,"r");
 if(cyclist_data == NULL) exit(FAIL);
 fscanf(cyclist_data,"%d",&total_cyc);
 cyclists = (cyclist* )malloc(total_cyc * sizeof(cyclist));
 if(cyclists==NULL){fprintf(stderr,"alloc fail");exit(FAIL);}
 while(fscanf(cyclist_data,"%s %d %d",name,&id,&lap_no) != EOF){
  str_copy(cyclists[cyc_no].name,name);
  cyclists[cyc_no].id = id;
  cyclists[cyc_no].lap_no = lap_no;
  cyclists[cyc_no].laps = (float*)malloc(lap_no*sizeof(float));
  if(cyclists[cyc_no].laps == NULL) exit(FAIL);
  for(i = 0; i < lap_no; i++)fscanf(cyclist_data,"%f",&cyclists[cyc_no].laps[i]);
  cyc_no++;
 }
 *(number) = cyc_no;
 return (cyclists);
}
int str_comp(char *s1,char *s2){//works
 int i;for(i = 0; s1[i] == s2[i] && s1[i] != '\0';i++);return s1[i] - s2[i];
}
void str_copy(char *s1,char *s2){ //works
 int i;for(i = 0; s2[i] != '\0';i++) s1[i] = s2[i];
}
int str_len(char *string){//works
 char  *s = string;while(*s!='\0')s++;return s - string;
}
/* EX -2 DONE*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CHAR (20+1)
#define SUCCESS 0
#define PASS "USED"
#define FAIL -1
int str_len(char*);
void read_file(char*);
int str_comp(char*,char*);
void str_copy(char*,char*);
char ***init_matrix(int,int);
void print_text(char***,int,int);
void sort_words(char***,int,int);
void put_word(char*,int,int,char***);
void sorted_print(int*,int,int,char***);
int main(int argc,char **argv){
 if(argc<2){printf("FAIL");exit(FAIL);}
 read_file(argv[1]);
 return SUCCESS;
}
void read_file(char *file_name){//works
 int i,j,rows,cols;char word[MAX_CHAR],***text_in;
 FILE *text_file = fopen(file_name,"r");
 if(text_file == NULL){printf("FAIL");exit(FAIL);}
 fscanf(text_file,"%d %d", &rows, &cols);
 text_in = init_matrix(rows,cols);
 for(i = 0; i < rows * cols; i++){
  fscanf(text_file, "%s" ,word);
  put_word(word,(i/cols),(i%cols),text_in);
 }
 sort_words(text_in,rows,cols);
}
void sort_words(char ***matrix,int rows,int cols){
  int i, j, min_idx, *idx;
  char **array, *min_word;
  /* allocate the final array, plus an auxiliary one */
  array = (char **)malloc(rows * cols * sizeof(char *));
  idx = (int *)calloc(rows, sizeof(int));
  if ((array == NULL) || (idx == NULL))exit(FAIL);
  /* merge the matrix rows */
  i = 0;
  while (i < rows * cols) {
    min_idx = -1;
    for (j = 0; j < rows; j++) {
      if (idx[j] < cols) {
        if ((min_idx == -1) || (str_comp(matrix[j][idx[j]], min_word)<0)) {
          min_idx = j; min_word = matrix[min_idx][idx[min_idx]];
        }
      }
    }
    array[i++] = matrix[min_idx][idx[min_idx]++];
  }
for(i=0;i<rows*cols;i++)printf("%d. %s\n",i,array[i]);
}
void sorted_print(int *positions,int size,int cols,char ***matrix){
 int i;for(i = 0; i < size; i++)
  printf("%d:%s\n",positions[i],matrix[positions[i] / cols][positions[i] % cols]);
}
void put_word(char *word,int x,int y,char ***text_out){//works
 text_out[x][y] = (char*)malloc( str_len(word) * sizeof(char));
 if(text_out[x][y] == NULL){fprintf(stderr,"FAIL");exit(FAIL);}
 str_copy(text_out[x][y],word);
}
void print_text(char ***matrix,int rows,int cols){//works
 int i,j;for(i = 0; i < rows; i++)for(j = 0; j < cols; j++)printf("%s\n",matrix[i][j]);
}
char ***init_matrix(int rows,int cols){//works
 char ***matrix;int i;matrix = (char***)malloc(rows * sizeof(char**));
 if(matrix == NULL){ printf("FAIL"); exit(FAIL);}
 for(i = 0; i < rows; i++){
  matrix[i] = (char**)malloc(cols * sizeof(char*));
  if(matrix[i] == NULL){printf("FAIL"); exit(FAIL);}
 }
 return matrix;
}
void str_copy(char *s1,char *s2){//works
 int i;for(i = 0; s2[i] != '\0';i++)s1[i] = s2[i];
 s1[i] ='\0';
}
int str_comp(char *s1,char *s2){//works
 int i;for(i = 0; s1[i] == s2[i] && s1[i] != '\0';i++);return s1[i] - s2[i];
}
int str_len(char *string){//works
 char  *s = string;while(*s!='\0')s++;return s - string;
}
