#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100],s2[100];
    int dp[100][100],max=0;

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

                if(dp[i][j]>max)
                    max=dp[i][j];
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }

    printf("Longest common substring length: %d",max);

    return 0;
}