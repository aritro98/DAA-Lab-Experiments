//Write a program to find the maximum profit nearest to but not
//exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
//Note: Declare a structure ITEM having data members item_id, item_profit, item_weight and
//profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order, according to their profit /weight.
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
}ITEM;
void swap(ITEM *a,ITEM *b){
    ITEM temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(ITEM arr[],int n,int i){
    int lgst=i;
    int lft=2*i+1;
    int rht=2*i+2;
    if (lft<n && arr[lft].profit_weight_ratio>arr[lgst].profit_weight_ratio)
        lgst=lft;
    if (rht<n && arr[rht].profit_weight_ratio>arr[lgst].profit_weight_ratio)
        lgst=rht;
    if (lgst!=i){
        swap(&arr[i],&arr[lgst]);
        heapify(arr,n,lgst);
    }
}
void heapsort(ITEM arr[],int n){
    for (int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for (int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
float fracKnapsack(ITEM items[],int n,float cpct){
    heapsort(items,n);
    float total_profit=0.0;
    printf("\nItem No\tProfit\tWeight\tAmount to be taken\n");
    for (int i=n-1;i>=0;i--){
        float amount_taken=0.0;
        if (items[i].item_weight<=cpct){
            amount_taken=1.0;
            cpct-=items[i].item_weight;
            total_profit+=items[i].item_profit;
        } 
        else if (cpct>0){
            amount_taken=cpct/items[i].item_weight;
            total_profit+=items[i].item_profit*amount_taken;
            cpct=0;
        }
        printf("%d\t%.6f\t%.6f\t%.6f\n",items[i].item_id,items[i].item_profit,items[i].item_weight,amount_taken);
    }
    return total_profit;
}
int main(){
    int n;
    float cpct;
    printf("Enter the number of items:");
    scanf("%d",&n);
    ITEM items[n];
    for (int i=0;i<n;i++){
        items[i].item_id=i+1;
        printf("Enter the profit and weight of item no %d:",i+1);
        scanf("%f %f",&items[i].item_profit,&items[i].item_weight);
        items[i].profit_weight_ratio=items[i].item_profit/items[i].item_weight;
    }
    printf("Enter the capacity of knapsack:");
    scanf("%f",&cpct);
    float max_profit=fracKnapsack(items,n,cpct);
    printf("Maximum Profit:%.6f\n",max_profit);
    return 0;
}
