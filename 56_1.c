#include <stdio.h>

int a[100][100],vis[100],v;

int dfs(int node,int parent)
{
    vis[node]=1;

    for(int i=0;i<v;i++)
    {
        if(a[node][i]==1)
        {
            if(vis[i]==0)
            {
                if(dfs(i,node))
                    return 1;
            }
            else if(i!=parent)
            {
                return 1;
            }
        }
    }

    return 0;
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
        a[w][u]=1;
    }

    for(int i=0;i<v;i++)
        vis[i]=0;

    int flag=0;

    for(int i=0;i<v;i++)
    {
        if(vis[i]==0)
        {
            if(dfs(i,-1))
            {
                flag=1;
                break;
            }
        }
    }

    if(flag)
        printf("Cycle detected");
    else
        printf("No cycle");

    return 0;
}