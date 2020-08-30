#include<stdio.h>
#include<stdlib.h>

typedef struct ele_ element;
typedef struct ele_{
 int id;
 struct ele_ *next;
};
void read_file(element**, char*);
element *new_element(element*, int);
int main(int argc, char **argv){
 if(argc != 2) printf("MISS\n");
 element *list = NULL;
 read_file(&list, argv[1]);
 while(list != NULL){
  printf("%d\t", list->id);
  list = list->next;
 }
 printf("\n");
 return 0;
}
void read_file(element **head, char *file){
 FILE *nums = fopen(file, "r"); int t;
 if(nums == NULL) printf("FILE\n");
 while(fscanf(nums, "%d", &t) != EOF)
  *head = new_element(*head, t);
}
element *new_element(element* head, int t){
 element *temp = (element*)malloc(sizeof(element));
 temp->next = NULL; temp->id = t;element *n = head;
 if(head == NULL){ head = temp; return head;}
 while(n->next != NULL) n = n->next;
 n->next = temp;
 return head;
}
