#include <stdio.h>

int main()
{
    int n,a[100],sum;
    int dp[100][100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter target sum: ");
    scanf("%d",&sum);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else if(a[i-1]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][sum])
        printf("Subset exists");
    else
        printf("No subset");

    return 0;
}