//Write a program to implement the matrix chain multiplication problem
//using M-table &amp; S-table to find optimal parenthesization of a matrix-chain product. Print the
//number of scalar multiplications required for the given input.
#include<stdio.h>
#include<limits.h>
void OptPar(int i,int j,int n,int bracket[n][n]){
    if (i==j){
        printf("A%d",i);
        return;
    }
    printf("(");
    OptPar(i,bracket[i][j],n,bracket);
    OptPar(bracket[i][j]+1,j,n,bracket);
    printf(")");
}
void matChain(int p[],int n){
    int m[n][n];
    int s[n][n];
    for (int i=1;i<n;i++){
        m[i][i]=0;
    }
    for (int L=2;L<n;L++){
        for (int i=1;i<n-L+1;i++){
            int j=i+L-1;
            m[i][j]=INT_MAX;
            for (int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    printf("M Table:\n");
    for (int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            if (i>j){
                printf("0 ");
            } 
            else{
                printf("%d ",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("S Table:\n");
    for (int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            if (i<j){
                printf("%d ",s[i][j]);
            } 
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("Optimal parenthesization:");
    OptPar(1,n-1,n,s);
    printf("\n");
    printf("Minimum number of multiplications is %d\n",m[1][n-1]);
}
int main(){
    int n;
    printf("Enter number of matrices:");
    scanf("%d",&n);
    int p[n+1];
    for (int i=0;i<n;i++){
        printf("Enter row and col size of A%d:",i+1);
        int row,col;
        scanf("%d %d",&row,&col);
        p[i]=row;
        if (i==n-1){
            p[i+1]=col;
        }
    }
    matChain(p,n+1);
    return 0;
}
