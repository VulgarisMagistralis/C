#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "item.h"
struct item{
 char *name;
 char *reg_no;
 int passed;
 int loaded;
}item;
/**ADDED**/
Item ITEMset(char *name,char *reg_no,int load,int pass){
 Item student = (Item)malloc(sizeof(struct item));
 student->reg_no = strdup(reg_no);
 student->name = strdup(name);
 student->loaded = load;
 student->passed = pass;
 return student;
}
/**ADDED**/
Item ITEMscan(){
 char name[MAX_NAME], reg_no[REG]; int loaded, passed;
 printf("Enter data with spaces: ");
 scanf("%s %s %d %d", name, reg_no, &loaded, &passed);
 Item tmp = ITEMsetvoid();
 if(tmp == NULL) return ITEMsetvoid();
 else{
  tmp->name = strdup(name);
  tmp->passed = passed;
  tmp->loaded = loaded;
  tmp->reg_no = strdup(reg_no);
 }
 return tmp;
}
void ITEMshow(Item data){
 printf("Name[%s]: %.4s. Loaded: %d. Passed: %d. \n",
 data->reg_no,
 data->name,
 data->loaded,
 data->passed);
}
int ITEMcheckvoid(Item data){
 Key k1, k2 = "";
 k1 = KEYget(data);
 if(KEYcompare(k1,k2)==0)return 1;
 else return 0;
}
Item ITEMsetvoid(){
 char name[MAX_NAME] = "", reg_no[REG] = "";
 Item tmp = (Item)malloc(sizeof(struct item));
 if(tmp != NULL){
  tmp->name = strdup(name);
  tmp->reg_no = strdup(reg_no);
  tmp->loaded = 0;
  tmp->passed = 0;
 }
 return tmp;
}
Key KEYscan(){ ///why
 char reg_no[MAX_NAME];Key k;
 scanf("%s",reg_no);
 k = strdup(reg_no);
 return k;
}
int KEYcompare(Key k1,Key k2){return strcmp(k1,k2);}
Key KEYget(Item data){ return data->reg_no;}
