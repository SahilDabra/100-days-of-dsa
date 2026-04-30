#include <stdio.h>

struct edge
{
    int u,v,w;
};

int main()
{
    int v,e,src;
    struct edge ed[100];
    int dist[100];

    printf("Enter number of vertices: ");
    scanf("%d",&v);

    printf("Enter number of edges: ");
    scanf("%d",&e);

    printf("Enter edges (u v w):\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
    }

    printf("Enter source: ");
    scanf("%d",&src);

    for(int i=0;i<v;i++)
        dist[i]=9999;

    dist[src]=0;

    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=ed[j].u;
            int w=ed[j].v;
            int wt=ed[j].w;

            if(dist[u]!=9999 && dist[u]+wt<dist[w])
            {
                dist[w]=dist[u]+wt;
            }
        }
    }

    int neg=0;

    for(int j=0;j<e;j++)
    {
        int u=ed[j].u;
        int w=ed[j].v;
        int wt=ed[j].w;

        if(dist[u]!=9999 && dist[u]+wt<dist[w])
        {
            neg=1;
        }
    }

    if(neg)
    {
        printf("Negative cycle detected");
    }
    else
    {
        printf("Shortest distances:\n");
        for(int i=0;i<v;i++)
        {
            printf("%d -> %d\n",i,dist[i]);
        }
    }

    return 0;
}