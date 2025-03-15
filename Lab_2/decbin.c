//Write a program in C to convert the first 'n' decimal numbers of a disc
//file to binary using recursion. Store the binary value in a separate disc file.
//Note# Read the value of 'n', source file name and destination file name from command line
//arguments. Display the decimal numbers and their equivalent binary numbers from the output file.
//Give the contents of the input disc file “inDec.dat” as 30 75 2564 …
//Contents of the output disc file “outBin.dat” as
//The binary equivalent of 30 is 0000000000011110
//The binary equivalent of 75 is 0000000001001011
//The binary equivalent of 2564 is 0000101000000100
#include<stdio.h>
#include<stdlib.h>
void decBin(int dec,FILE *outFile){
    if (dec==0){
        fprintf(outFile,"0000000000000000\n");
        return;
    }
    decBin(dec/2,outFile);
    fprintf(outFile,"%d",dec%2);
}
int main(int argc,char *argv[]){
    if (argc!=4){
        printf("Usage:%s <n> <input_file> <output_file>\n",argv[0]);
        return 1;
    }
    int n=atoi(argv[1]);
    char *inFileName=argv[2];
    char *outFileName=argv[3];
    FILE *inFile=fopen("inDec.dat","r");
    FILE *outFile=fopen("outBin.dat","w");
    if (!inFile || !outFile){
        printf("Error opening files.\n");
        return 1;
    }
    int dec;
    for (int i=0;i<n;++i){
        if (fscanf(inFile,"%d",&dec)!=1){
            break;
        }
        fprintf(outFile,"The binary equivalent of %d is ",dec);
        decBin(dec,outFile);
        fprintf(outFile,"\n");
    }
    printf("Conversion completed. Check '%s' for binary values.\n",outFileName);
    fclose(inFile);
    fclose(outFile);
    return 0;
}
