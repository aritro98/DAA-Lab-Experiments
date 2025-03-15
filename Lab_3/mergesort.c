//Write a menu driven program to sort list of array elements using Merge
//Sort technique and calculate the execution time only to sort the elements. Count the number of comparisons.
//Note#
//● To calculate execution time, assume that single program is under execution in the CPU.
//● Number of elements in each input file should vary from 300 to 500 entries.
//● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40…..,
//Store the result in “outMergeAsce.dat”.
//● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60….,
//Store the result in “outMergeDesc.dat”.
//● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …,
//Store the result in “outMergeRand.dat”
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int* read_data(const char* filename,int* size){
    FILE* file=fopen(filename,"r");
    if (!file){
        printf("Error: Could not open file %s\n",filename);
        exit(EXIT_FAILURE);
    }
    int* data=malloc(500*sizeof(int));
    int i=0;
    while (fscanf(file,"%d",&data[i])!=EOF && i<500){
        i++;
    }
    *size=i;
    fclose(file);
    return data;
}
void write_data(const char* filename,int* data,int size){
    FILE* file=fopen(filename,"w");
    if (!file){
        printf("Error: Could not open file %s\n",filename);
        exit(EXIT_FAILURE);
    }
    for (int i=0;i<size;i++){
        fprintf(file,"%d ",data[i]);
    }
    fclose(file);
}
void merge_sort(int arr[],int l,int r,int* comps){
    if (l<r){
        int m=l+(r-l)/2;
        merge_sort(arr,l,m,comps);
        merge_sort(arr,m+1,r,comps);
        int i,j,k;
        int n1=m-l+1;
        int n2=r-m;
        int* L=malloc(n1*sizeof(int));
        int* R=malloc(n2*sizeof(int));
        for (i=0;i<n1;i++){
            L[i]=arr[l+i];
        }
        for (j=0;j<n2;j++){
            R[j]=arr[m+1+j];
        }
        i=0;
        j=0;
        k=l;
        while (i<n1 && j<n2){
            (*comps)++;
            if (L[i]<=R[j]){
                arr[k]=L[i];
                i++;
            } 
            else{
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        while (i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }
        while (j<n2){
            arr[k]=R[j];
            j++;
            k++;
        }
        free(L);
        free(R);
    }
}
void print_array(int arr[],int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void menu(){
    int option;
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option:");
    scanf("%d",&option);
    const char* input_file;
    const char* output_file;
    switch (option){
        case 1:
            input_file="inAsce.dat";
            output_file="outMergeAsce.dat";
            break;
        case 2:
            input_file="inDesc.dat";
            output_file="outMergeDesc.dat";
            break;
        case 3:
            input_file="inRand.dat";
            output_file="outMergeRand.dat";
            break;
        case 4:
            printf("Exiting...\n");
            return;
        default:
            printf("Invalid option\n");
            return;
    }
    int size;
    int* data=read_data(input_file,&size);
    printf("Before Sorting:");
    print_array(data,size);
    int comps=0;
    LARGE_INTEGER frequency,start,end;
    QueryFreq(&frequency);
    QueryCount(&start);
    merge_sort(data,0,size-1,&comps);
    QueryCount(&end);
    double elapsed_time=(double)(end.QuadPart-start.QuadPart)/frequency.QuadPart*1e9;
    write_data(output_file,data,size);
    printf("After Sorting:");
    print_array(data,size);
    printf("Number of Comparisons:%d\n",comps);
    printf("Execution Time:%.0f nanoseconds\n",elapsed_time);
    free(data);
}
int main(){
    menu();
    return 0;
}
