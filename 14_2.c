#include <stdio.h>

int main()
{
    int n,a[10][10];

    printf("Enter size of matrix: ");
    scanf("%d",&n);

    printf("Enter elements of matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    // transpose
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }

    // reverse each row
    for(int i=0;i<n;i++)
    {
        int l=0,r=n-1;
        while(l<r)
        {
            int t=a[i][l];
            a[i][l]=a[i][r];
            a[i][r]=t;
            l++;
            r--;
        }
    }

    printf("Rotated matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}