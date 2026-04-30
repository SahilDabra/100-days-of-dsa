#include <stdio.h>

int main()
{
    int n,a[100],k;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter window size: ");
    scanf("%d",&k);

    printf("Maximums: ");

    for(int i=0;i<=n-k;i++)
    {
        int max=a[i];

        for(int j=1;j<k;j++)
        {
            if(a[i+j]>max)
            {
                max=a[i+j];
            }
        }

        printf("%d ",max);
    }

    return 0;
}