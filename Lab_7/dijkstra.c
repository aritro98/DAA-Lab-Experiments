#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5
int minDist(int dist[],int sptSet[]){
    int min=INT_MAX,min_index;
    for (int v=0;v<V;v++)
        if (sptSet[v]==0 && dist[v]<=min)
            min=dist[v],min_index=v;
    return min_index;
}
void Path(int parent[],int j){
    if (parent[j]==-1)
        return;
    Path(parent,parent[j]);
    printf("->%d",j+1);
}
void Sol(int dist[],int n,int parent[],int src){
    printf("Source Destination Cost Path\n");
    for (int i=0;i<V;i++){
        printf("%d \t %d \t %d \t",src+1,i+1,dist[i]);
        if (i!=src){
            printf("%d",src+1);
            Path(parent,i);
        }
        printf("\n");
    }
}
void dijkstra(int graph[V][V],int src){
    int dist[V];
    int sptSet[V];
    int parent[V];
    for (int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=0;
        parent[i]=-1;
    }
    dist[src]=0;
    for (int count=0;count<V-1;count++){
        int u=minDist(dist,sptSet);
        sptSet[u]=1;
        for (int v=0;v<V;v++)
            if (!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
                parent[v]=u;
            }
    }
    Sol(dist,V,parent,src);
}
int main(){
    FILE *file=fopen("C:\\Users\\KIIT\\OneDrive\\Documents\\DAA_Lab\\inDiAdjMat1.dat","r");
    int graph[V][V];
    for (int i=0;i<V;i++)
        for (int j=0;j<V;j++)
            fscanf(file,"%d",&graph[i][j]);
    fclose(file);
    int src;
    printf("Enter the Source Vertex:");
    scanf("%d",&src);
    dijkstra(graph,src-1);
    return 0;
}
