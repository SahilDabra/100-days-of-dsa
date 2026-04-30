#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int max=a[0],cur=a[0];

    for(int i=1;i<n;i++)
    {
        if(cur + a[i] > a[i])
            cur = cur + a[i];
        else
            cur = a[i];

        if(cur > max)
            max = cur;
    }

    printf("Maximum subarray sum: %d",max);

    return 0;
}