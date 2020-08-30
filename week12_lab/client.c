#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "st.h"
#include "treePublic.h"
typedef struct no_list list_no;
typedef struct{
 int no;
 list_no *next;
}no_list;
/**ADDED**/
int exists(no_list*,int);
no_list *add(int, no_list*);
/**ADDED**/
int main(int argc,char **argv) {
 Item item; Key k; int i, cont, maxN;
 printf("Input size of hash table to guarantee load factor < 1/2:");
 scanf("%d", &maxN);
 ST st = STinit(maxN);
 cont = 1;
 /**ADDED**/
 link head;char *wanted;int height,true=1;
 FILE *text_file; no_list *heights = NULL;
 node_t *root = createEmptyTree();
 /**ADDED**/
 while(cont){
  printf("\nOps\n");
  printf("1.Insert\n");
  printf("2.Search\n");
  printf("3.Delete \n");
  printf("4.Display \n");
  printf("5.Terminate\n");
  printf("6.Read Data \n");
  printf("7.Display Tree\n");
  printf("8.BST to Table \n");
  printf("9.Last Exercise \n");
  printf("Enter your choice: ");
  if(scanf("%d", &i) <= 0){
   printf("Integers only!\n");
   exit(0);
  }else {
   printf("\n");
   switch(i){
    case 1:
     printf("Enter item: \n");
     item = ITEMscan();
     if(ITEMcheckvoid(STsearch(st, KEYget(item))))
      STinsert(st, item);
     break;
    case 2:
     printf("Enter key: \n"); k = KEYscan();
     if(ITEMcheckvoid(STsearch(st, k))) printf("data with given key not found!\n");
     else printf("data with given key found!\n");
     break;
    case 3:
     printf("Enter key: \n");k = KEYscan();
     if(ITEMcheckvoid(STsearch(st, k)))
      printf("data with given key not in symbol table!\n");
     else STdelete(st, k);
     break;
    case 4:
     STdisplay(st,stdout); break;
    case 5:
     cont = 0; break;
    case 6:
     if(argv[1] == NULL)printf("You didnt enter file name");
     else{
      text_file = fopen(argv[1],"r");
      freeTree(root);
      root = readTree(text_file);
     }
     break;
    case 7:
     writeTree(stdout, root, INORDER); break;
    case 8:
     if(root == NULL)printf("read file first! GODDAMIT!\n");
     else tree_to_hash(root,st);
    break;
    case 9:
     head = list_unique(st);
     while(true){
      wanted=strdup(getKEY(head));
      head = next_link(head);
      height = get_height(root, wanted, 0);
      if(!exists(heights, height)) heights = add(height, heights);
      if(head == NULL) true = 0;
     }
     while(heights != NULL){
      print_t(heights->no,root,0);
      heights = heights->next;
     }
    break;
    default:
     printf("Invalid option\n");
   }
  }
 }
 return 0;
}
no_list *add(int number, no_list *list){
 no_list *x = (no_list*)malloc(sizeof(no_list));
 x->no = number;
 x->next = list;
 return x;
}
int exists(no_list *list, int number){
 while(list != NULL){
  if(list->no == number)return 1;
  list = list->next;
 }
 return 0;
}

