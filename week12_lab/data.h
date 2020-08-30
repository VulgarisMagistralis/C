#ifndef _DATA_INCLUDED
#define _DATA_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define REG 10
#define MAXC 21
typedef struct{
 char *reg_no;
 char *name;
 int loaded;
 int passed;
}data_t;
char *get_reg(data_t);
int compare(data_t, data_t);
int readData(FILE*, data_t*);
void writeData(FILE*, data_t);
#endif
