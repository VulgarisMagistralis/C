#include "treePublic.h"
#define OK 1
#define KO 0
int main(void){
  node_t *root,*tmp;data_t d;int retValue, end = 0; char row[MAXC];
  FILE *fp = NULL; root = NULL;root = createEmptyTree();
 /*New data*/
  int num_of_nodes,path_no,key1,key2;
  int *array = NULL;
  while(!end){
    fprintf(stdout,"User selection\n");
    fprintf(stdout,"\t1) Insert one single node\n\t2) Cancel one single node\n\t3) Search a node\n");
    fprintf(stdout,"\t4) Print BST on stdout\n\t5) Write BST on file\n\t6) Read BST from file\n" );
    fprintf(stdout,"\t7) Compute min and max\n\t8) Terminate\n\t9) Extras\n\t> ");scanf("%1s",row);
    switch(atoi(row)){
      case 1:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue == 0){
          fprintf (stderr, "Input error.\n");
          exit (0);
        }
	root = insert (root, d);
	break;
      case 2:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input error.\n");
          exit (0);
        }
	root = delete (root, d);
	break;
      case 3:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if(retValue == 0){
          fprintf (stderr, "Input error.\n");
          exit (0);
        }
	tmp = searchI (root, d);
	if(tmp != NULL) {
	  fprintf (stdout, "Iterative Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Iterative Search: Not Found\n");
        }
	tmp = searchR (root, d);
	if (tmp  != NULL) {
	  fprintf (stdout, "Recursive Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Recursive Search: Not Found\n");
        }
	break;
      case 4:
	writeTree (stdout, root, INORDER);
	break;
      case 5:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);
        if (strcmp (row, "stdout") == 0) {
          fp = stdout;
        } else {
   	  fp = fopen (row, "w");
        }
        if (fp == NULL) {
         fprintf (stderr, "Error Opening File %s\n", row);
         break;
	}
	writeTree (fp, root, PREORDER);
        if (strcmp (row, "stdout") != 0) {
	  fclose(fp);
	}
	break;
      case 6:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);
	fp = fopen (row, "r");
	if (fp == NULL) {
	  fprintf (stderr, "Error Opening File %s\n", row);
	} else {
	  freeTree (root);
	  root = readTree (fp);
	}
	break;
      case 7:
        fprintf (stdout, "Tree minimum iterative: "); 
        tmp = treeMinI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree minimum recursive: "); 
        tmp = treeMinR (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum iterative: ");
        tmp = treeMaxI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum recursive: "); 
        tmp = treeMaxR (root);
        writeData (stdout, getData(tmp));
	break;
      case 8:
	end = 1;
	break;
      case 9:
        fprintf(stdout,"\n\t\t1)Node Count\n\t\t2)Total Node Count\n\t\t3)Level Count");
	fprintf(stdout,"\n\t\t4)Path Count\n\t\t5)Difference\n\t\t>");fscanf(stdin,"%1s",row);
        switch(atoi(row)){
         case 1:
           countNode(root, &array);
           printf("%d %d %d \n",array[0],array[1],array[2]);
	   array = NULL;
           break;
         case 2:
   	   num_of_nodes = count_all(root);
	   printf("Number:%d \n",num_of_nodes);
   	   break;
         case 3:
 	   wrap_level(root, &array, 0);
           break;
	 case 4:
	   wrap_path(root, &path_no, 0);
	   break;
        case 5:
	   printf("\n\t\tEnter the keys:\n\t\t>");
	   fscanf(stdin, "%d %d", &key1, &key2);
	   wrap_visit(root, key1, key2);
	   break;
        }
      default:
	fprintf (stderr, "Unknown Option.\n");
	break;
    }
  }
  freeTree(root);
  return (OK);
}



