#include <stdio.h>

int main()
{
    int v,a[100][100];

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

    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(a[i][k]+a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    printf("Shortest path matrix:\n");
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