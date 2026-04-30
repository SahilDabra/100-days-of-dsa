#include <stdio.h>

int main()
{
    int v,a[100][100],dist[100],vis[100]={0},src;

    printf("Enter number of vertices: ");
    scanf("%d",&v);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter source: ");
    scanf("%d",&src);

    for(int i=0;i<v;i++)
        dist[i]=9999;

    dist[src]=0;

    for(int i=0;i<v-1;i++)
    {
        int min=9999,u;

        for(int j=0;j<v;j++)
        {
            if(vis[j]==0 && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        vis[u]=1;

        for(int j=0;j<v;j++)
        {
            if(a[u][j]!=0 && vis[j]==0 && dist[u]+a[u][j]<dist[j])
            {
                dist[j]=dist[u]+a[u][j];
            }
        }
    }

    printf("Shortest distances:\n");
    for(int i=0;i<v;i++)
    {
        printf("%d -> %d\n",i,dist[i]);
    }

    return 0;
}