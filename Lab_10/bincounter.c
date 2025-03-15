#include<stdio.h>
#define BITS 6
void count(int *counter,int cost,const char *operation){
    for (int i=BITS-1;i>=0;i--){
        printf("%d\t",counter[i]);
    }
    printf("%-10s %d\n",operation,cost);
}
void increment(int *counter,int *hob,int *totcost){
    int cost=1;
    int i=0;
    while (i<=*hob && counter[i]==1){
        counter[i]=0;
        cost++;
        i++;
    }
    if (i<BITS){
        counter[i]=1;
        if (i>*hob){
            *hob=i;
        }
    }
    *totcost+=cost;
    count(counter,*totcost,"Increment");
}
void reset(int *counter,int *hob,int *totcost){
    int cost=*hob+1;
    for (int i=0;i<=*hob;i++){
        counter[i]=0;
    }
    *hob=0;
    *totcost+=cost;
    count(counter,*totcost,"Reset");
}
int main(){
    int counter[BITS]={0};
    int hob=0;
    int totcost=0;
    printf("Bit 5\tBit 4\tBit 3\tBit 2\tBit 1\tBit 0\tOperation  Cost\n");
    count(counter,totcost,"Initial");
    increment(counter,&hob,&totcost);
    reset(counter,&hob,&totcost);
    increment(counter,&hob,&totcost);
    reset(counter,&hob,&totcost);
    increment(counter,&hob,&totcost);
    reset(counter,&hob,&totcost);
    return 0;
}
