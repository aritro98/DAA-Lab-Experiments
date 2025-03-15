//Write a program to find out the second smallest and second largest element stored in an array of n integers.
#include<stdio.h>
#include<limits.h>
void secsmalarg(int arr[],int n,int *secsma,int *seclarg){
    int sma=INT_MAX,larg=INT_MIN;
    *secsma=INT_MAX;
    *seclarg=INT_MIN;
    for (int i=0;i<n;i++){
        if (arr[i]<sma){
            *secsma=sma;
            sma=arr[i];
        }
        else if (arr[i]<*secsma && arr[i]!=sma){
            *secsma=arr[i];
        }
        if (arr[i]>larg){
            *seclarg=larg;
            larg=arr[i];
        }
        else if (arr[i]>*seclarg && arr[i]!=larg){
            *seclarg = arr[i];
        }
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
    int secsma,seclarg;
    secsmalarg(arr,n,&secsma,&seclarg);
    if (secsma==INT_MAX){
        printf("There is no second smallest element.\n");
    }
    else{
        printf("The second smallest element is:%d\n",secsma);
    }
    if (seclarg==INT_MIN){
        printf("There is no second largest element.\n");
    }
    else{
        printf("The second largest element is:%d\n",seclarg);
    }
    return 0;
}
