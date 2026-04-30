#include <stdio.h>

int main()
{
    int n,a[10][10],sum=0;

    printf("Enter size of matrix: ");
    scanf("%d",&n);

    printf("Enter elements of matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(int i=0;i<n;i++)
    {
        sum += a[i][i];
        sum += a[i][n-i-1];
    }

    if(n%2==1)
        sum -= a[n/2][n/2];

    printf("Diagonal sum: %d",sum);

    return 0;
}