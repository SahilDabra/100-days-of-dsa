#include <stdio.h>

int main()
{
    int n,coins[100],amt,dp[100][100];

    printf("Enter number of coins: ");
    scanf("%d",&n);

    printf("Enter coin values: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d",&amt);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amt;j++)
        {
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else if(coins[i-1] <= j)
                dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    printf("Ways: %d",dp[n][amt]);

    return 0;
}