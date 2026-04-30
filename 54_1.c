#include <stdio.h>

int main()
{
    int v,e,u,w,a[100][100]={0};

    printf("Enter number of vertices: ");
    scanf("%d",&v);

    printf("Enter number of edges: ");
    scanf("%d",&e);

    printf("Enter edges:\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&w);

        a[u][w]=1;
        a[w][u]=1;
    }

    printf("Adjacency Matrix:\n");

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}