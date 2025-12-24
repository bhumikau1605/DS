#include<stdio.h>
void dfs(int);
int n,i,j,a[10][10],vis[10],count;
void main(){
    int i,j,src;
    printf("Name: BHUMIKA U \nUSN: 1BM24CS073\n");
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
        vis[i]=0;
    }
    printf("DFS Traversal: \n");
    for(i=1;i<=n;i++){
        if(vis[i])dfs(i);
    }
    for(i=0;i<n;i++){
        if(vis[i])count++;
    }
    if(count==n){
        printf("Graph is connected\n");
    }else{
        printf("Graph is not connected\n");
    }
}
void dfs(int v){
        vis[v]=1;
        printf("%d",v);
        for(j=1;j<=n;j++){
            if(a[v][j]==1 && vis[j]==0) dfs(j);
        }
}
