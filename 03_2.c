#include <stdio.h>

int main()
{
    int n,a[100],sum=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }

    int exp = n*(n+1)/2;

    printf("Missing number: %d", exp - sum);

    return 0;
}