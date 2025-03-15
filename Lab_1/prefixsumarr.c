//Given an array arr[] of size N, find the prefix sum of the array. A prefix
//sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
//arr[0] + arr[1] + arr[2] . . . arr[i].
#include<stdio.h>
void PrefixSum(int arr[],int prefixSum[],int n){
    prefixSum[0]=arr[0];
    for (int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
}
int main(){
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Initial Array:");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    int prefixSum[n];
    PrefixSum(arr,prefixSum,n);
    printf("\nPrefix Sum Array:");
    for (int i=0;i<n;i++){
        printf("%d ",prefixSum[i]);
    }
    return 0;
}
