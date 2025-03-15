#include<stdio.h>
#include<string.h>
void incFitstring(char *fitstring){
    int len=strlen(fitstring);
    int i=0;
    while (i<len){
        if (fitstring[i]=='0'){
            fitstring[i]='1';
            break;
        } 
        else{
            fitstring[i]='0';
            if (i+1<len && fitstring[i+1]=='0'){
                fitstring[i+1]='1';
                break;
            }
        }
        i++;
    }
    if (i>=len) {
        fitstring[len]='1';
        fitstring[len+1]='\0';
    }
}
void decFitstring(char *fitstring){
    int len=strlen(fitstring);
    int i=0;
    while (i<len){
        if (fitstring[i]=='1'){
            fitstring[i]='0';
            if (i>0 && fitstring[i-1]=='1'){
                fitstring[i-1]='0';
                if (i+1<len){
                    fitstring[i+1]='1';
                }
            }
            break;
        }
        i++;
    }
    for (int j=len-1;j>=0;--j){
        if (fitstring[j]=='1') break;
        fitstring[j] = '\0';
    }
}
int main(){
    char fitstring[100];
    printf("Enter the fitstring:");
    scanf("%s",fitstring);
    printf("Original fitstring:%s\n",fitstring);
    incFitstring(fitstring);
    printf("After increment:%s\n",fitstring);
    decFitstring(fitstring);
    decFitstring(fitstring);
    printf("After two decrements:%s\n",fitstring);
    return 0;
}
