#include <stdio.h>

int main()
{
    int r,c,a[10][10],flag=1;

    printf("Enter number of rows and columns: ");
    scanf("%d%d",&r,&c);

    if(r!=c)
    {
        printf("Not symmetric");
        return 0;
    }

    printf("Enter elements of matrix:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                flag=0;
                break;
            }
        }
        if(flag==0) break;
    }

    if(flag)
        printf("Matrix is symmetric");
    else
        printf("Matrix is not symmetric");

    return 0;
}