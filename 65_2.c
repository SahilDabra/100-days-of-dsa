#include <stdio.h>
#include <string.h>

int ispal(char s[],int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int main()
{
    char s[100];
    int dp[100][100];

    printf("Enter string: ");
    scanf("%s",s);

    int n=strlen(s);

    for(int i=0;i<n;i++)
        dp[i][i]=0;

    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j=i+len-1;

            if(ispal(s,i,j))
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=9999;

                for(int k=i;k<j;k++)
                {
                    int cost = dp[i][k] + dp[k+1][j] + 1;

                    dp[i][j]=min(dp[i][j],cost);
                }
            }
        }
    }

    printf("Minimum cuts: %d",dp[0][n-1]);

    return 0;
}