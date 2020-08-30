#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 21
/* This code is slighlty modified from
   the exam version; I did few modifications
   which I was not able to do in examination
   time. This data structure consumes too much
   space but it facilitates function operations.
   reduces the complexity and makes it easier
   to read at fisrt look. Cenk TUNCBILEK 240174 */
typedef struct emp emp_t;
typedef struct firm firm_t;
struct emp{
 char *id;
 char mark;
 emp_t *next;
 firm_t *f_curr;
 firm_t *f_ranks;
};
struct firm{
 char *id;
 char mark;
 firm_t *next;
 emp_t *e_curr;
 emp_t *e_ranks;
};
/* PROTOTYPES */
void assign(emp_t*, firm_t*);
int check(emp_t*, firm_t*, int);
void unassign(emp_t*, firm_t*);
int check_mark(emp_t*, int);
int check_sta(emp_t*, firm_t*, int);
void display(firm_t*, emp_t*, FILE*, int);
void add_emp(firm_t**, char*, char*);
int get_e_rank(firm_t*, emp_t*, int);
int get_f_rank(emp_t*, firm_t*, int);
emp_t *check_emp(emp_t*, char*);
firm_t *check_firm(firm_t*, char*);
int pair_r(firm_t*, emp_t*, int);
void add_firm(emp_t**, char*, char*);
emp_t *new_emp(emp_t**, char*, char*, int);
firm_t *new_firm(firm_t**, char*, char*, int);
void read_file(int*, emp_t**, firm_t**, char*);
/* FUNCTIONS */
/* Main calls read and recursive pairing
   function then prints the result */
int main(int argc, char **argv){
 if(argc != 2) exit(0);
 int n = 0;
 firm_t *firms = NULL;
 emp_t *employees = NULL;
 read_file(&n, &employees, &firms, argv[1]);
 if(pair_r(firms, employees,n))display(firms, employees, stdout, n);
 else fprintf(stderr, "Instability inevitable. \n");
 return 0;
}
/* Recursively pairing firms with employees
   until all conditions are satisfied on my
   paper I waited to check until n*n, in here
   I put my second checking in the termination
   condition which shortened the running time
   and removes the need for level check  */
int pair_r(firm_t *firms, emp_t *emps, int n){
 if(check_mark(emps,n))if(check(emps,firms,n)) return 1;
 int i, j; emp_t *e; firm_t *f = firms;
 for(i = 0; i < n; i++){
  e = emps;
  for(j = 0; j < n; j++){
   if(!f->mark && !e->mark){
    assign(e, f);
    if(pair_r(firms, emps, n)) return 1;
    unassign(e, f);
   }
   e = e->next;
  }
  f = f->next;
 }
 return 0;
}
/* Checks if all firms and employess
   are matched before the final check */
int check_mark(emp_t *emps, int n){
 int i; emp_t *e = emps;
 for(i = 0; i < n; i++){
  if(!e->mark) return 0;
  e = e->next;
 }
 return 1;
}
/* Returns the rank of the currently
   sent employee for the firm */
int get_e_rank(firm_t *f, emp_t *emp, int n){
 emp_t *e = f->e_ranks; int i, rank = 0;
 for(i = 0; i < n; i++){
  if(strcmp(e->id,emp->id) == 0) return rank;
  e = e->next;
  rank++;
 }
}
/* Returns the rank of the currently sent
   firm for the employee */
int get_f_rank(emp_t *e, firm_t *firm, int n){
 firm_t *f = e->f_ranks; int i, rank = 0;
 for(i = 0; i < n; i++){
  if(strcmp(f->id,firm->id) == 0) return rank;
  f = f->next;
  rank++;
 }
}
/* Checks instability condition for a pair */
int check_sta(emp_t *e, firm_t *f, int n){
 if(get_f_rank(e, e->f_curr, n) > get_f_rank(e, f, n))
  if(get_e_rank(f, f->e_curr, n) > get_e_rank(f, e, n))
   return 0;
 return 1;
}
/* Visits all pairs to check the
   instability condition */
int check(emp_t *emp, firm_t *firm, int n){
 emp_t *e = emp; firm_t *f = firm; int i, j;
 for(i = 0; i < n; i++){
  e = emp;
  for(j = 0; j < n; j++){
   if(e->mark && f->mark) if(!check_sta(e, f, n)) return 0;
   e = e->next;
  }
 f = f->next;
 }
 return 1;
}
/* Pairing an employee and a firm */
void assign(emp_t *e, firm_t *f){
 f->e_curr = e;
 e->f_curr = f;
 f->mark = 1;
 e->mark = 1;
}
/* Removing the assigned pair */
void unassign(emp_t *e, firm_t *f){
 f->e_curr = NULL;
 e->f_curr = NULL;
 e->mark = 0;
 f->mark = 0;
}
/*Reading data from the file and creates rank lists
  for each employee and firm. This function is different
  on my paper because i didnt realize N = 4 was not a
  constant so, I modified accordingly */
void read_file(int *n, emp_t **emp, firm_t **firm, char *name){
 int i,j;char id[MAX],temp[MAX];
 FILE *file = fopen(name, "r");
 if(file == NULL) exit(0);
 fscanf(file, "%d", n);
 for(i = 0;i < 2*(*n); i++){
  fscanf(file, "%s", id);
  for(j = 0; j < (*n); j++){
   fscanf(file, "%s", temp);
   if(i<*n) *emp= new_emp(emp, temp, id, j);
   else *firm = new_firm(firm, temp, id, j);
  }
 }
}
/* Initializing a firm
   with default values */
firm_t *init_firm(char *id){
 firm_t *f = malloc(sizeof(firm_t));
 if(f == NULL) exit(0);
 f->mark = 0;
 f->next = NULL;
 f->e_curr = NULL;
 f->e_ranks = NULL;
 f->id = strdup(id);
 return f;
}
/* Intializing an employee
   with default values  */
emp_t *init_emp(char *id){
 emp_t *e = malloc(sizeof(emp_t));
 if(e == NULL) exit(0);
 e->mark = 0;
 e->next = NULL;
 e->f_curr = NULL;
 e->f_ranks = NULL;
 e->id = strdup(id);
 return e;
}
/* Adds a firm into the rank list
   of the passed employee */
void add_firm(emp_t **e, char *firm_name, char *id){
 emp_t *emp = check_emp(*e, id);
 firm_t *temp = emp->f_ranks;
 firm_t *f = init_firm(firm_name);
 if(temp == NULL) emp->f_ranks = f;
 else{
  while(temp->next != NULL) temp = temp->next;
  temp->next = f;
 }
}
/* Adds an employee into the rank list of
   the passed firm if it is not on list */
void add_emp(firm_t **f, char *emp_name, char *id){
 firm_t *firm = check_firm(*f, id);
 emp_t *temp = firm->e_ranks;
 emp_t *e = init_emp(emp_name);
 if(temp == NULL) firm->e_ranks = e;
 else{
  while(temp->next != NULL) temp = temp->next;
  temp->next = e;
 }
}
/* Creates a firm for the global reading */
firm_t *new_firm(firm_t **f, char *emp_name, char *id, int flag){
 if(flag == 0){
  firm_t *temp = init_firm(id);
  if(*f == NULL) *f = temp;
  temp->next = *f;
  *f = temp;
 }
 add_emp(f, emp_name, id);
 return *f;
}
/* Creates an employee for the global reading */
emp_t *new_emp(emp_t **e, char *firm_name, char *id, int flag){
 if(flag == 0){
  emp_t *temp = init_emp(id);
  if(*e == NULL) *e = temp;
  temp->next = *e;
  *e = temp;
 }
 add_firm(e, firm_name, id);
 return *e;
}
/* Checks if the employee is present */
emp_t *check_emp(emp_t *emp, char *id){
 emp_t *e = emp;
 while(e != NULL)
  if(strcmp(e->id, id) == 0) return e;
  else e = e->next;
 return NULL;
}
/* Checks if the firm is present */
firm_t *check_firm(firm_t *firm, char *id){
 firm_t *f = firm;
 while(f != NULL)
  if(strcmp(f->id, id) == 0) return f;
  else f = f->next;
 return NULL;
}
/* Prints from both firm perspective
   and employee perspective, data is
   stored for both sides */
void display(firm_t *firm, emp_t *emp, FILE *fp, int n){
 int i; emp_t *e = emp; firm_t* f = firm;
 for(i = 0; i < n; i++){
  printf("Pairs on e: %s %s\n", e->id, e->f_curr->id);
  printf("Pairs on f: %s %s\n", f->id, f->e_curr->id);
  f = f->next; e = e->next;
 }
}
