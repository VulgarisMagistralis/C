#include "data.h"
int readData(FILE *f, data_t* student){
 char reg[REG], name[MAXC]; int load, pass;
 int check = fscanf(f,"%s %s %d %d",reg,name,&load,&pass);
 student->reg_no = strdup(reg);
 student->name = strdup(name);
 student->loaded = load;
 student->passed = pass;
 return check;
}
void writeData(FILE *f, data_t student){
 fprintf(f,"%s %s %d %d\n",
 student.reg_no,
 student.name,
 student.loaded,
 student.passed);
 return;
}
int compare(data_t s1, data_t s2){
 int i = 0;
 while(i < 9){
  if(s1.reg_no[i] < s2.reg_no[i]) return -1;
  if(s1.reg_no[i] > s2.reg_no[i]) return 1;
  i++;
 }
 return 0;
}
char *get_reg(data_t data){return (data.reg_no);}
