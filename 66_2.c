#include <stdio.h>

int main()
{
    int n,a[100],sum=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }

    if(sum%2!=0)
    {
        printf("Cannot be partitioned");
        return 0;
    }

    int target=sum/2;
    int dp[100][100];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
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

    if(dp[n][target])
        printf("Can be partitioned");
    else
        printf("Cannot be partitioned");

    return 0;
}