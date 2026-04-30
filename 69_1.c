#include <stdio.h>

int n,a[100][100];

int safe(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        if(a[i][c]==1)
            return 0;
    }

    for(int i=r,j=c;i>=0 && j>=0;i--,j--)
    {
        if(a[i][j]==1)
            return 0;
    }

    for(int i=r,j=c;i>=0 && j<n;i--,j++)
    {
        if(a[i][j]==1)
            return 0;
    }

    return 1;
}

int solve(int r)
{
    if(r==n)
        return 1;

    for(int c=0;c<n;c++)
    {
        if(safe(r,c))
        {
            a[r][c]=1;

            if(solve(r+1))
                return 1;

            a[r][c]=0;
        }
    }

    return 0;
}

int main()
{
    printf("Enter N: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;

    if(solve(0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution");
    }

    return 0;
}