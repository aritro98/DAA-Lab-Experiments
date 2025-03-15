//Write a program to read 'n' integers from a disc file that must contain
//some duplicate values and store them into an array. Perform the following operations on the array.
//a) Find out the total number of duplicate elements.
//b) Find out the most repeating element in the array.
#include <stdio.h>
int countDup(int arr[],int n){
    int count=0;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            if (arr[i]==arr[j]){
                count++;
                break;
            }
        }
    }
    return count;
}
int mostRep(int arr[],int n){
    int maxcount=0;
    int mostrep=-1;
    for (int i=0;i<n;++i){
        int count=1;
        for (int j=i+1;j<n;++j){
            if (arr[i]==arr[j]){
                count++;
            }
        }
        if (count>maxcount){
            maxcount=count;
            mostrep=arr[i];
        }
    }
    return mostrep;
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d integers:\n",n);
    for (int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    int dupcount=countDup(arr,n);
    printf("Total number of duplicate elements:%d\n",dupcount);
    int mostrep=mostRep(arr,n);
    printf("The most repeating element:%d\n",mostrep);
    return 0;
}
