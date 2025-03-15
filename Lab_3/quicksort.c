//Write a menu driven program to sort a list of elements in ascending
//order using Quick Sort technique. Each choice for the input data has its own disc file. A separate
//output file can be used for sorted elements. After sorting display the content of the output file
//along with number of comparisons. Based on the partitioning position for each recursive call,
//conclude the input scenario is either best-case partitioning or worst-case partitioning.
//Note#
//● The worst-case behavior for quicksort occurs when the partitioning routine produces one
//subproblem with n-1 elements and one with 0 elements. The best-case behaviour
//occurred in most even possible split, PARTITION produces two subproblems, each of size no more than n/2.
//● Number of elements in each input file should vary from 300 to 500 entries.
//● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40…..,
//Store the result in “outQuickAsce.dat”.
//● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60….,
//Store the result in “outQuickDesc.dat”.
//● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …,
//Store the result in “outQuickRand.dat”
#include<stdio.h>
#include<stdlib.h>
int comps=0;
void quicksort(int arr[],int low,int high);
int partition(int arr[],int low,int high);
void readFromFile(const char *filename,int arr[],int *size);
void writeToFile(const char *filename,int arr[],int size);
void displayFileContent(const char *filename);
void displayMenu();
void quicksort(int arr[],int low,int high){
    if (low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low-1);
    for (int j=low;j<high;j++){
        comps++;
        if (arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i+1);
}
void readFile(const char *filename,int arr[],int *size){
    FILE *file=fopen(filename,"r");
    if (!file){
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    int i=0;
    while (fscanf(file,"%d",&arr[i])!=EOF){
        i++;
    }
    *size=i;
    fclose(file);
}
void writeFile(const char *filename,int arr[],int size){
    FILE *file=fopen(filename,"w");
    if (!file){
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    for (int i=0;i<size;i++){
        fprintf(file,"%d ",arr[i]);
    }
    fclose(file);
}
void displayFileContent(const char *filename){
    FILE *file=fopen(filename,"r");
    if (!file){
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    int value;
    while (fscanf(file,"%d",&value)!=EOF){
        printf("%d ",value);
    }
    printf("\n");
    fclose(file);
}
void menu(){
    int choice;
    int arr[500];
    int size;
    const char *inputFile,*outputFile;
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d",&choice);
    comps=0;
    switch (choice){
        case 1:
            inputFile="inAsce.dat";
            outputFile="outQuickAsce.dat";
            break;
        case 2:
            inputFile="inDesc.dat";
            outputFile="outQuickDesc.dat";
            break;
        case 3:
            inputFile="inRand.dat";
            outputFile="outQuickRand.dat";
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option!\n");
    }
    readFile(inputFile,arr,&size);
    printf("Before Sorting:");
    displayFileContent(inputFile);
    quicksort(arr,0,size-1);
    writeFile(outputFile,arr,size);
    printf("After Sorting:");
    displayFileContent(outputFile);
    printf("Number of Comparisons:%d\n",comps);
    if (choice==3){
        if (comps>size*size/4){
            printf("Scenario: Worst-case partitioning\n");
        } 
        else{
            printf("Scenario: Best-case partitioning\n");
        }
    }
}
int main(){
    menu();
    return 0;
}
