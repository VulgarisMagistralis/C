#include "treePrivate.h"
////////////////////////
void wrap_visit(node_t *root,int key1,int key2){
 int distance = visit(root, key1);
 distance = distance + visit(root, key2);
 printf(" %d? ", distance);
}
int visit(node_t *root,int target){
 if(root->val == target) return 0;
 if(root->val > target) return (visit(root->left,target) + 1);
 else return (visit(root->right,target) + 1);
}
///////////////////// is it true ?
void wrap_path(node_t *root,int *no_path,int length){
 length = count_all(root);
 *no_path = path_count(root);
 printf("%d %d",length ,*no_path);
}
int path_count(node_t *root){
 if(root != NULL && root->left == NULL && root->right == NULL) return 1;
 int left = path_count(root->left);
 int right = path_count(root->right);
 return left + right;
}
///////////////////
static void count_rec(node_t *root,int *none,int *sing,int *doub){
 if(root == NULL) return;
 if(root->left == NULL && root->right == NULL){*none = *none + 1; return;}
 if(root->left == NULL || root->right == NULL){*sing = *sing + 1;
  if(root->left != NULL) count_rec(root->left,none,sing,doub);
  else count_rec(root->right,none,sing,doub);
 }
 if(root->left != NULL && root->right != NULL){
  *doub = *doub + 1;
  count_rec(root->left ,none,sing,doub);
  count_rec(root->right,none,sing,doub);
 }
}
void countNode(node_t *root, int **array){
 int *temp = malloc(3 * sizeof(int));
 int sing = 0, none = 0, doub = 0;
 count_rec(root,&none,&sing,&doub);
 *(temp+0) = none;*(temp+1) = sing;
 *(temp+2) = doub;*array = temp;
}
///////////
int count_all(node_t *root){
 int left_no, right_no;
 if(root == NULL) return 0;
 right_no = count_all(root->right);
 left_no = count_all(root->left);
 return (right_no + left_no + 1);
}
///////////
void wrap_level(node_t *root,int **array,int level){
 int height_tree = get_height(root);
 int *temp = malloc(height_tree*sizeof(int));
 count_level(root, temp, level);
 print_array(temp, height_tree);
 *array = temp;
}
void count_level(node_t *root,int *array,int level){
 if(root == NULL)return;
 array[level] = array[level] + 1;
 count_level(root->left,array,level+1);
 count_level(root->right,array,level+1);
}
//utility
int get_height(node_t *root){
 if(root == NULL) return 0;
 int left_height = get_height(root->left);
 int right_height = get_height(root->right);
 if(right_height >= left_height)
  return right_height + 1;
 else return left_height + 1;
}
void print_array(int *array,int height){
 int index;
 for(index = height-1; index >= 0; index--)
  printf("nodes at height %d = %d\n",index,array[index]);
}

