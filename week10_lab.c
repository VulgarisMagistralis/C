/*Labyrinth v2*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
char **init_laby(int,int);
void pre_mark(char**,char**,int,int);
void print_laby(char**,int,int);
void laby_copy(char**,char**,int,int);
char **read_laby(char*,int*,int*);
int move_r(char**,char**,int,int,int,int,int,int);
int available(int,int,int,int,char**);
void find_sol1(char**,int,int,int,int);
void find_start(char**,int,int,int*,int*);
int main(int argc,char **argv){
 int rows, cols, start_x, start_y, step = 0;
 char **laby=read_laby(argv[1],&rows,&cols);
 print_laby(laby, rows, cols);
 find_start(laby,rows, cols,&start_x,&start_y);
 find_sol1(laby, rows, cols, start_x, start_y);
 return SUCCESS;
}
void find_sol1(char **laby,int rows,int cols,int x,int y){
 char **marked = init_laby(rows, cols); int step = 1000;
 pre_mark(laby, marked, rows, cols);
 step = move_r(laby, marked, rows, cols, x, y, step, 1000);
 printf("Solution(%d steps):\n",step);
 //print_laby(marked,rows,cols);
}
int move_r(char **best_path,char **curr_path,int rows,int cols,int x,int y,int step,int best_step){
 if(step >= best_step) return best_step;
 if(curr_path[x][y] == 'G'){
  if(step < best_step){
  best_step = step;
  laby_copy(best_path,curr_path,rows,cols);
  return best_step;
  }
 if(curr_path[x][y] != ' ') return best_step;
 curr_path[x][y] = 'P';
 }
 int direction, next_x = 0, next_y = 0;
 int directions[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
 for(direction=0;direction<(rows*cols);direction++){
  next_x = x + directions[(direction % 4)][0];
  next_y = y + directions[(direction % 4)][1];
  curr_path[next_x][next_y] = 'P';
  if(available(next_x,next_y,rows,cols,curr_path))
   move_r(best_path,curr_path,rows,cols,next_x,next_y,step+1,best_step);
 }
 curr_path[next_x][next_y] = ' ';
 return best_step;
}
void laby_copy(char **m1, char **m2, int rows, int cols){
  int i,j;for(i=0;i<rows;i++)for(j=0;j<cols;j++)m1[i][j]=m2[i][j];
}
int available(int x,int y,int rows,int cols,char **marked){//works
 if(x < 0) return FAILURE; if(y < 0) return FAILURE;
 if(x >= rows) return FAILURE;if(y >= cols)return FAILURE;
 if(marked[x][y] != ' ' && marked[x][y] != '#') return FAILURE;
 return SUCCESS;
}
void pre_mark(char **laby,char **marked,int rows,int cols){//works
 int i,j;
 for(i = 0; i < rows; i++){
  for(j = 0; j < cols; j++){
   if(laby[i][j] == '*') marked[i][j] = '*';
   else if(laby[i][j] == '#') marked[i][j] = 'X';
   else if(laby[i][j] == '@') marked[i][j] = 'H';
   else marked[i][j] = ' ';
  }
 }
}

void find_start(char **laby,int rows,int cols,int *x,int *y){//works
 int i,j;
 for(i = 0; i < rows; i++){for(j = 0; j < cols; j++){
   if(laby[i][j] == '@'){ *x = i; *y = j; return; }
  }
 }
 fprintf(stderr,"Begining point nowhere to be found :(\n");
 exit(FAILURE);
}
char **read_laby(char *file_name,int *rows,int *cols){ //works
 int i = 0,j = 0; char c;
 FILE *laby_file = fopen(file_name, "r");
 fscanf(laby_file,"%d%d %*c", rows,cols);
 char **labyrinth=init_laby(*rows,*cols);
 while(fscanf(laby_file, "%c", &c) != EOF){
  if(c == '\n'){i++; j = 0;}
  else{labyrinth[i][j]=c;j++;}
 }
 return labyrinth;
}
char **init_laby(int rows,int cols){//works
 char **laby=(char**)malloc(rows*sizeof(char*));
 int i; if(laby == NULL) exit(FAILURE);
 for(i = 0; i < rows; i++){
  laby[i]=(char*)malloc(cols*sizeof(char));
  if(laby[i] == NULL) exit(FAILURE);
 }
 return laby;
}
void print_laby(char **laby,int rows,int cols){ //works
 int i,j;
 for(i = 0; i < rows; i++){for(j = 0; j < cols; j++){fprintf(stdout,"%c", laby[i][j]);}
 fprintf(stdout,"\n");
 }
}
/*Labyrinth v1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
char **init_laby(int,int);
void pre_mark(char**,char**,int,int);
void print_laby(char**,int,int);
char **read_laby(char*,int*,int*);
int move_r(char**,char**,int,int,int,int);
int available(int,int,int,int,char**);
void find_sol1(char**,int,int,int,int);
void find_start(char**,int,int,int*,int*);
int main(int argc,char **argv){
 int rows, cols, start_x, start_y;
 char **laby=read_laby(argv[1],&rows,&cols);
 print_laby(laby, rows, cols);
 find_start(laby,rows,cols,&start_x, &start_y);
 find_sol1(laby, rows, cols, start_x, start_y);
 return SUCCESS;
}
void find_sol1(char **laby,int rows,int cols,int x,int y){
 char **marked = init_laby(rows, cols);
 pre_mark(laby, marked, rows, cols);
 if(move_r(laby,marked,rows,cols,x,y)){
  printf("Solution:\n");print_laby(marked,rows,cols);
 }
}
int move_r(char **laby,char **marked,int rows,int cols,int x,int y){
 if(laby[x][y] == 'G') return SUCCESS;
 int direction, next_x = 0, next_y = 0;
 int directions[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
 for(direction=0;direction<(rows*cols);direction++){
  next_x = x + directions[(direction % 4)][0];
  next_y = y + directions[(direction % 4)][1];
  if(available(next_x,next_y,rows,cols,marked)){
   marked[next_x][next_y] = 'P';
   if(move_r(laby,marked,rows,cols,next_x,next_y)) return SUCCESS;
   marked[next_x][next_y] = ' ';
  }
 }
 return FAILURE;
}
int available(int x,int y,int rows,int cols,char **marked){//works
 if(x < 0) return FAILURE; if(y < 0) return FAILURE;
 if(x >= rows) return FAILURE;if(y >= cols)return FAILURE;
 if(marked[x][y] != ' ' && marked[x][y] != '#') return FAILURE;
 return SUCCESS;
}
void pre_mark(char **laby,char **marked,int rows,int cols){//works
 int i,j;
 for(i = 0; i < rows; i++){
  for(j = 0; j < cols; j++){
   if(laby[i][j] == '*') marked[i][j] = '*';
   else if(laby[i][j] == '#') marked[i][j] = 'X';
   else if(laby[i][j] == '@') marked[i][j] = 'H';
   else marked[i][j] = ' ';
  }
 }
}
void find_start(char **laby,int rows,int cols,int *x,int *y){//works
 int i,j;
 for(i = 0; i < rows; i++){for(j = 0; j < cols; j++){
   if(laby[i][j] == '@'){ *x = i; *y = j; return; }
  }
 }
 fprintf(stderr,"Begining point nowhere to be found :(\n");
 exit(FAILURE);
}
char **read_laby(char *file_name,int *rows,int *cols){ //works
 int i = 0,j = 0; char c;
 FILE *laby_file = fopen(file_name, "r");
 fscanf(laby_file,"%d%d %*c", rows,cols);
 char **labyrinth=init_laby(*rows,*cols);
 while(fscanf(laby_file, "%c", &c) != EOF){
  if(c == '\n'){i++; j = 0;}
  else{labyrinth[i][j]=c;j++;}
 }
 return labyrinth;
}
char **init_laby(int rows,int cols){//works
 char **laby=(char**)malloc(rows*sizeof(char*));
 int i; if(laby == NULL) exit(FAILURE);
 for(i = 0; i < rows; i++){
  laby[i]=(char*)malloc(cols*sizeof(char));
  if(laby[i] == NULL) exit(FAILURE);
 }
 return laby;
}
void print_laby(char **laby,int rows,int cols){ //works
 int i,j;
 for(i = 0; i < rows; i++){for(j = 0; j < cols; j++){fprintf(stdout,"%c", laby[i][j]);}
 fprintf(stdout,"\n");
 }
}
*/
