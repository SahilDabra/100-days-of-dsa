#include <stdio.h>

int main()
{
    int v,e,u,w,start;
    int a[100][100]={0},vis[100]={0},q[100];
    int front=0,rear=-1;

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

    printf("Enter starting node: ");
    scanf("%d",&start);

    rear++;
    q[rear]=start;
    vis[start]=1;

    printf("BFS: ");

    while(front<=rear)
    {
        int x=q[front];
        front++;

        printf("%d ",x);

        for(int i=0;i<v;i++)
        {
            if(a[x][i]==1 && vis[i]==0)
            {
                rear++;
                q[rear]=i;
                vis[i]=1;
            }
        }
    }

    return 0;
}