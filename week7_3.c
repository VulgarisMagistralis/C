/*RECO*/
/*Binary Search-in sorted array
#include<stdio.h>
#include<stdlib.h>
void reverse_print(char*);
void print(char*);
int bin_search(int,int*,int,int);
int main(int argc,char **argv){
 int array[10];int left,right;
 //int position = bin_search(atoi(argv[1]),array,left,right);
 //reverse_print(argv[1]);
 print(argv[1]);
 printf("\n");
 return 0;
}
void print(char *string){
 if(*string == '\0') return;
 fprintf(stdout,"%c",*string);
 print(string + 1);
}
void reverse_print(char *string){
 if(*string == '\0') return;
 reverse_print(string + 1);
 fprintf(stdout,"%c",*string);
}

int bin_search(int number,int array[10],int left,int right){
 if(left == right) return left;
 else return -1;/* not found *//*
 int middle = (left + right)/2;
 if(array[middle] >= number)return (bin_search(number,array,left,middle));
 else return (bin_search(number,array,middle+1,right));
}
*/
/*LISTS
//typedef struct node *link;/*very interesting

typedef struct nodes{
 int item;
 nodes *next;
}node;
node *deletion(node *head,int item){
 if(head == NULL) return NULL;
 if(node->item == item){
  node *head1 = head->next;
  free(head);
  return head1;
 }
 head->next = deletion(head->next,item);
 return head;//if item is not on the list
}
int count(node *x){ //head pointer
 if(x == NULL) return 0;
 return 1+ count(x->next);
}
void traverse(node *head){//clean code
 if(head == NULL) return;
 printf("%d",head->item);
 traverse(head->next);
}
void rev_trave(node *head){//print from last
 if(head == NULL) return;
 rev_trave(head->next);
 printf("%d",item);
}
*/
