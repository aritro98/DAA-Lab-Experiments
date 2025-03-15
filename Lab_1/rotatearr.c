//Write a function to ROTATE_RIGHT(p1, p2) right an array for first p2
//elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p & q.
//Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.
#include<stdio.h>
void EXCHANGE(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
void ROTATE_RIGHT(int *p1,int p2){
    if (p2<=1) return;
    int last=*(p1+p2-1);
    for (int i=p2-1;i>0;i--){
        EXCHANGE(p1+i,p1+i-1);
    }
    *p1=last;
}
int main(){
    int n,p2;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number of elements to rotate:");
    scanf("%d",&p2);
    if (p2>n){
        printf("Number of elements to rotate cannot exceed the array size.\n");
        return 1;
    }
    printf("Original array:");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    ROTATE_RIGHT(arr,p2);
    printf("Array after rotation:");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
