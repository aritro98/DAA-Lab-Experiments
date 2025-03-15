//Write a program in C to find GCD of two numbers using recursion.
//Read all pair of numbers from a file and store the result in a separate file.
//Note# Source file name and destination file name taken from command line arguments. 
//The source file must contain at least 20 pairs of numbers.
//Give the contents of the input disc file “inGcd.dat” as 8 12 20 45 30 80
//Contents of the output disc file “outGcd.dat” as
//The GCD of 8 and 12 is 4
//The GCD of 20 and 45 is 5
//The GCD of 30 and 80 is 10
#include <stdio.h>
int gcd(int a,int b){
    if (b==0)
        return a;
    return gcd(b,a%b);
}
int main(int argc,char *argv[]){
    if (argc!=3){
        printf("Usage: %s <input_file> <output_file>\n",argv[0]);
        return 1;
    }
    char *inFileName=argv[1];
    char *outFileName=argv[2];
    FILE *inputFile=fopen("inGcd.dat","r");
    if (!inputFile){
        printf("Error opening input file.\n");
        return 1;
    }
    FILE *outputFile=fopen("outGcd.dat","w");
    if (!outputFile){
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }
    int num1,num2;
    while (fscanf(inputFile,"%d %d",&num1,&num2)==2){
        int result=gcd(num1,num2);
        fprintf(outputFile,"The GCD of %d and %d is %d\n",num1,num2,result);
    }
    fclose(inputFile);
    fclose(outputFile);
    printf("Results written to %s.\n",argv[2]);
    return 0;
}
