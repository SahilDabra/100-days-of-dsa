#include <stdio.h>

int main()
{
    int r,c,a[10][10],flag=1;

    printf("Enter number of rows and columns: ");
    scanf("%d%d",&r,&c);

    printf("Enter elements of matrix:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);

    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(a[i][j]!=a[i-1][j-1])
            {
                flag=0;
                break;
            }
        }
        if(flag==0) break;
    }

    if(flag)
        printf("Matrix is Toeplitz");
    else
        printf("Matrix is not Toeplitz");

    return 0;
}