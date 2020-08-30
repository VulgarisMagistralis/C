/*Common divisor
#include<stdio.h>
#include<stdlib.h>

int gcd(int x,int y){
 if(y == 0) return x;
 gcd(y, x % y);
}
int main(int argc,char **argv){
 int divisor;
 if(argv[1] > argv[2])
  divisor = gcd(atoi(argv[1]),atoi(argv[2]));
  else
  divisor = gcd(atoi(argv[2]),atoi(argv[1]));
 printf("%d \n\n",divisor);
 return 0;
}
/*determinant*/

#include<stdio.h>
#include<stdlib.h

int get_det(int mat[][MAX]){
 return (mat[0][0]*mat[1][1] -mat[1][0]*mat[0][1]);
}
void minor(int mat[][MAX],int i,int j,int n,int mat2[][MAX]){
 int r,c,rr,cc;
 for(rr=0,r=0;r<n;rr++)
  if(r != i){
   for(cc=0,c=o;c<nc++){
    mat2[rr][cc] = mat[r][c];
    cc++;
   }
  rr++;
  }
}
int det(int mat[][MAX],int n){
 int sum=0,k,j,i,r,c,temp[MAX][MAX];
 if(n == 2) return (get_det(mat));
 for(k = 0; k < n; k++){
  minor(a,0,k,n,temp);
  sum = sum +mat[0][k]*pow(-1,k)*det(temp,n-1);
 }
 return sum;
}



