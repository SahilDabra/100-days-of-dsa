#include <stdio.h>
#include <string.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    char s[100],rev[100];
    int dp[100][100];

    printf("Enter string: ");
    scanf("%s",s);

    int n=strlen(s);

    for(int i=0;i<n;i++)
    {
        rev[i]=s[n-1-i];
    }
    rev[n]='\0';

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s[i-1]==rev[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    printf("LPS length: %d",dp[n][n]);

    return 0;
}