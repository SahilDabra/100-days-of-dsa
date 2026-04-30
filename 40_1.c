#include <stdio.h>

int main()
{
    int n,a[100],f[100]={0},k;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter value of k: ");
    scanf("%d",&k);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j])
            {
                f[i]++;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(f[i]<f[j])
            {
                int t=f[i];
                f[i]=f[j];
                f[j]=t;

                int t2=a[i];
                a[i]=a[j];
                a[j]=t2;
            }
        }
    }

    printf("Top elements: ");
    for(int i=0;i<k;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}