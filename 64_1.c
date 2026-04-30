#include <stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int n,a[100],dp[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dp[i]=1;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    int ans=0;

    for(int i=0;i<n;i++)
    {
        if(dp[i]>ans)
            ans=dp[i];
    }

    printf("LIS length: %d",ans);

    return 0;
}