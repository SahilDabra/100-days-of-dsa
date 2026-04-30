#include <stdio.h>

int main()
{
    int r,c,a[10][10],flag=1;

    printf("Enter number of rows and columns: ");
    scanf("%d%d",&r,&c);

    if(r!=c)
    {
        printf("Not an identity matrix");
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
            if(i==j && a[i][j]!=1)
                flag=0;

            if(i!=j && a[i][j]!=0)
                flag=0;
        }
    }

    if(flag)
        printf("Matrix is identity");
    else
        printf("Matrix is not identity");

    return 0;
}