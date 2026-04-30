#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int max=a[0],sum=0;

    for(int i=0;i<n;i++)
    {
        sum = sum + a[i];

        if(sum > max)
            max = sum;

        if(sum < 0)
            sum = 0;
    }

    printf("Maximum subarray sum: %d",max);

    return 0;
}