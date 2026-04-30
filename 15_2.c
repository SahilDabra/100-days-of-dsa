#include <stdio.h>

int main()
{
    int r,c,a[10][10],row[10]={0},col[10]={0};

    printf("Enter number of rows and columns: ");
    scanf("%d%d",&r,&c);

    printf("Enter elements of matrix:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(row[i]==1 || col[j]==1)
                a[i][j]=0;

    printf("Result matrix:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}