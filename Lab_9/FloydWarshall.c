#include<stdio.h>
#include<stdlib.h>
#define INF 99999
void Matrix(int n,int dist[n][n]){
    printf("Shortest Path Weight Matrix:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (dist[i][j]==INF)
                printf("INF ");
            else
                printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}
void Path(int u,int v,int predecessor[u+1][v+1]){
    if (u!=v && predecessor[u][v]==-1){
        printf("No path exists.\n");
        return;
    }
    int path[100],count=0;
    int current=v;
    while (current!=u){
        path[count++]=current;
        current=predecessor[u][current];
    }
    path[count++]=u;
    for (int i=count-1;i>=0;i--){
        printf("%d",path[i]+1);
        if (i!=0) printf("-->");
    }
}
void FloydWarshall(int n,int graph[n][n],int src,int dest){
    int dist[n][n],predecessor[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            dist[i][j]=graph[i][j];
            if (i==j || graph[i][j]==INF)
                predecessor[i][j]=-1;
            else
                predecessor[i][j]=i;
        }
    }
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    predecessor[i][j]=predecessor[k][j];
                }
            }
        }
    }
    Matrix(n,dist);
    printf("Shortest Path from vertex %d to vertex %d:",src+1,dest+1);
    Path(src,dest,predecessor);
    printf("\nPath weight:%d\n",dist[src][dest]);
}
int main(){
    int n,src,dest;
    FILE *file=fopen("C:\\Users\\KIIT\\OneDrive\\Documents\\DAA_Lab\\inDiAdjMat2.dat","r");
    if (file==NULL){
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int graph[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            fscanf(file,"%d",&graph[i][j]);
            if (graph[i][j]==0 && i!=j)
                graph[i][j]=INF;
        }
    }
    fclose(file);
    printf("Enter the source and destination vertex:");
    scanf("%d %d",&src,&dest);
    src--;
    dest--;
    FloydWarshall(n,graph,src,dest);
    return 0;
}
