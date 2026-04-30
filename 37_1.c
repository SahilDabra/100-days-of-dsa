#include <stdio.h>

int main()
{
    int n,a[100],x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Queue: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    int max=a[0],pos=0;

    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            pos=i;
        }
    }

    printf("\nDeleted element: %d",max);

    for(int i=pos;i<n-1;i++)
    {
        a[i]=a[i+1];
    }

    n--;

    printf("Queue after deletion: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}