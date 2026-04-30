#include <stdio.h>

int main()
{
    int v,e,u,w,a[100][100]={0},ind[100]={0};
    int q[100],front=0,rear=-1;

    printf("Enter number of vertices: ");
    scanf("%d",&v);

    printf("Enter number of edges: ");
    scanf("%d",&e);

    printf("Enter edges:\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&w);
        a[u][w]=1;
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(a[i][j]==1)
                ind[j]++;
        }
    }

    for(int i=0;i<v;i++)
    {
        if(ind[i]==0)
        {
            rear++;
            q[rear]=i;
        }
    }

    printf("Topological order: ");

    while(front<=rear)
    {
        int x=q[front];
        front++;

        printf("%d ",x);

        for(int i=0;i<v;i++)
        {
            if(a[x][i]==1)
            {
                ind[i]--;

                if(ind[i]==0)
                {
                    rear++;
                    q[rear]=i;
                }
            }
        }
    }

    return 0;
}