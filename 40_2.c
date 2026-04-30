#include <stdio.h>

int main()
{
    int n,a[100],res[100];

    printf("Enter number of days: ");
    scanf("%d",&n);

    printf("Enter temperatures: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        res[i]=0;

        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i])
            {
                res[i]=j-i;
                break;
            }
        }
    }

    printf("Result: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",res[i]);
    }

    return 0;
}