#include <stdio.h>

int main()
{
    int v,a[100][100],vis[100]={0};
    int min,u,w,total=0;

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

    vis[0]=1;

    printf("Edges in MST:\n");

    for(int k=0;k<v-1;k++)
    {
        min=9999;

        for(int i=0;i<v;i++)
        {
            if(vis[i]==1)
            {
                for(int j=0;j<v;j++)
                {
                    if(vis[j]==0 && a[i][j]!=0 && a[i][j]<min)
                    {
                        min=a[i][j];
                        u=i;
                        w=j;
                    }
                }
            }
        }

        printf("%d - %d\n",u,w);
        total=total+min;

        vis[w]=1;
    }

    printf("Total cost: %d",total);

    return 0;
}