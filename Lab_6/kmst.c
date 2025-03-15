//Given an undirected weighted connected graph G(V, E). Apply Krushkal’s algorithm to
//● Find the minimum spanning tree T(V, E’) and Display the selected edges of G.
//● Display total cost of the minimum spanning tree T.
//Note: Nodes will be numbered consecutively from 1 to n (user input), and edges will have
//varying weight. The weight matrix of the graph can be represented from the user’s input in the
//given format. The expected output could be the selected edge and the corresponding cost of the edge as per the sample output.
#include<stdio.h>
#include<stdlib.h>
struct Edge{
    int src,dest,weight;
};
struct Subset{
    int parent;
    int rank;
};
int find(struct Subset subsets[],int i){
    if (subsets[i].parent!=i){
        subsets[i].parent=find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(struct Subset subsets[],int x,int y){
    int xroot=find(subsets,x);
    int yroot=find(subsets,y);
    if (subsets[xroot].rank<subsets[yroot].rank){
        subsets[xroot].parent=yroot;
    }
    else if (subsets[xroot].rank>subsets[yroot].rank){
        subsets[yroot].parent=xroot;
    }
    else{
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
}
int compareEdges(const void* a,const void* b){
    struct Edge* a1=(struct Edge*)a;
    struct Edge* b1=(struct Edge*)b;
    return a1->weight>b1->weight;
}
void KruskalMST(struct Edge edges[],int V,int E){
    struct Edge result[V];
    int e=0,i=0;
    qsort(edges,E,sizeof(edges[0]),compareEdges);
    struct Subset subsets[V];
    for (int v=0;v<V;++v){
        subsets[v].parent=v;
        subsets[v].rank=0;
    }
    while (e<V-1 && i<E){
        struct Edge next_edge=edges[i++];
        int x=find(subsets,next_edge.src);
        int y=find(subsets,next_edge.dest);
        if (x!=y){
            result[e++]=next_edge;
            Union(subsets,x,y);
        }
    }
    printf("Edge Cost\n");
    int totalWeight=0;
    for (i=0;i<e;++i){
        printf("%d--%d  %d\n",result[i].src+1,result[i].dest+1,result[i].weight);
        totalWeight+=result[i].weight;
    }
    printf("Total Weight of the Spanning Tree:%d\n",totalWeight);
}
int main(){
    int V,E;
    printf("Enter the number of vertices and edges:");
    scanf("%d %d",&V,&E);
    struct Edge edges[E];
    printf("Enter the edges (source,destination,weight):\n");
    for (int i=0;i<E;i++){
        scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
        edges[i].src--;
        edges[i].dest--;
    }
    KruskalMST(edges,V,E);
    return 0;
}
