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
    char s1[100],s2[100];
    int dp[100][100];

    printf("Enter string 1: ");
    scanf("%s",s1);

    printf("Enter string 2: ");
    scanf("%s",s2);

    int n=strlen(s1);
    int m=strlen(s2);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    printf("LCS length: %d",dp[n][m]);

    return 0;
}