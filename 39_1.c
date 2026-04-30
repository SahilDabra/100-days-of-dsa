#include <stdio.h>

int main()
{
    int n,a[100],x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        a[i]=x;

        int j=i;

        while(j>0)
        {
            int p=(j-1)/2;

            if(a[p]>a[j])
            {
                int t=a[p];
                a[p]=a[j];
                a[j]=t;

                j=p;
            }
            else
            {
                break;
            }
        }
    }

    printf("Min Heap: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}