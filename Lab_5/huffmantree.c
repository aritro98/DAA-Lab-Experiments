//Huffman coding assigns variable length code words to fixed length
//input characters based on their frequencies or probabilities of occurrence. Given a set of
//characters along with their frequency of occurrences, write a c program to construct a Huffman tree.
//Note:
//● Declare a structure SYMBOL having members alphabet and frequency. Create a Min-
//Priority Queue, keyed on frequency attributes.
//● Create an array of structures where size=number of alphabets.
//Input:
//Enter the number of distinct alphabets: 6
//Enter the alphabets: a b c d e f
//Enter its frequencies: 45 13 12 16 9 5
//Output:
//In-order traversal of the tree (Huffman): a c b f e d
#include<stdio.h>
#include<stdlib.h>
struct Node{
    char alphabet;
    int freq;
    struct Node *lft,*rht;
};
struct SYMBOL{
    char alphabet;
    int freq;
};
struct Node* create(char alphabet, int freq){
    struct Node* newn=(struct Node*)malloc(sizeof(struct Node));
    newn->alphabet=alphabet;
    newn->freq=freq;
    newn->lft=newn->rht=NULL;
    return newn;
}
struct Node* MinHeapNode(struct SYMBOL sym){
    return create(sym.alphabet,sym.freq);
}
void swap(struct Node** a,struct Node** b){
    struct Node* temp=*a;
    *a=*b;
    *b=temp;
}
void minHeapify(struct Node** minHeap,int size,int idx){
    int smst=idx;
    int lft=2*idx+1;
    int rht=2*idx+2;
    if (lft<size && minHeap[lft]->freq<minHeap[smst]->freq)
        smst=lft;
    if (rht<size && minHeap[rht]->freq<minHeap[smst]->freq)
        smst=rht;
    if (smst!=idx){
        swap(&minHeap[smst],&minHeap[idx]);
        minHeapify(minHeap,size,smst);
    }
}
void MinHeap(struct Node** minHeap,int size){
    int n=size-1;
    for (int i=(n-1)/2;i>=0;--i){
        minHeapify(minHeap,size,i);
    }
}
struct Node* extMin(struct Node** minHeap,int* size){
    struct Node* temp=minHeap[0];
    minHeap[0]=minHeap[*size-1];
    --(*size);
    minHeapify(minHeap,*size,0);
    return temp;
}
void insMinHeap(struct Node** minHeap,int* size,struct Node* node){
    ++(*size);
    int i=*size-1;
    while (i && node->freq<minHeap[(i-1)/2]->freq){
        minHeap[i]=minHeap[(i-1)/2];
        i=(i-1)/2;
    }
    minHeap[i]=node;
}
struct Node* HuffmanTree(struct SYMBOL syms[],int size){
    struct Node** minHeap=(struct Node**)malloc(size *sizeof(struct Node*));
    for (int i=0;i<size;++i){
        minHeap[i]=MinHeapNode(syms[i]);
    }
    MinHeap(minHeap,size);
    while (size!=1){
        struct Node* lft=extMin(minHeap,&size);
        struct Node* rht=extMin(minHeap,&size);
        struct Node* top=create('$',lft->freq+rht->freq);
        top->lft=lft;
        top->rht=rht;
        insMinHeap(minHeap,&size,top);
    }
    struct Node* root=extMin(minHeap,&size);
    free(minHeap);
    return root;
}
void inorder(struct Node* root){
    if (root){
        inorder(root->lft);
        if (root->alphabet!='$')
            printf("%c ",root->alphabet);
        inorder(root->rht);
    }
}
int main(){
    int n;
    printf("Enter the number of distinct alphabets:");
    scanf("%d",&n);
    struct SYMBOL syms[n];
    printf("Enter the alphabets:");
    for (int i=0;i<n;++i){
        scanf(" %c",&syms[i].alphabet);
    }
    printf("Enter its frequencies:");
    for (int i=0;i<n;++i){
        scanf("%d",&syms[i].freq);
    }
    struct Node* root=HuffmanTree(syms,n);
    printf("In-order traversal of the tree (Huffman):");
    inorder(root);
    printf("\n");
    return 0;
}
