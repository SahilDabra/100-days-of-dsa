#include <stdio.h>

int a[100][100],vis[100],st[100],top=-1,v;

void dfs(int node)
{
    vis[node]=1;

    for(int i=0;i<v;i++)
    {
        if(a[node][i]==1 && vis[i]==0)
        {
            dfs(i);
        }
    }

    top++;
    st[top]=node;
}

int main()
{
    int e,u,w;

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
    }

    for(int i=0;i<v;i++)
        vis[i]=0;

    for(int i=0;i<v;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }

    printf("Topological order: ");
    while(top!=-1)
    {
        printf("%d ",st[top]);
        top--;
    }

    return 0;
}