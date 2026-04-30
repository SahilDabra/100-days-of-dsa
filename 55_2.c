#include <stdio.h>

int a[100][100],vis[100],v;

void dfs(int x)
{
    printf("%d ",x);
    vis[x]=1;

    for(int i=0;i<v;i++)
    {
        if(a[x][i]==1 && vis[i]==0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int e,u,w,start;

    printf("Enter number of vertices: ");
    scanf("%d",&v);

    printf("Enter number of edges: ");
    scanf("%d",&e);

    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            a[i][j]=0;

    printf("Enter edges:\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&w);
        a[u][w]=1;
        a[w][u]=1;
    }

    printf("Enter starting node: ");
    scanf("%d",&start);

    printf("DFS: ");
    dfs(start);

    return 0;
}