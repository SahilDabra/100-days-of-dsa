#include <stdio.h>

int main()
{
    int n,a[100],k;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter value of k: ");
    scanf("%d",&k);

    k = k % n;

    int l=0,r=n-1;
    while(l<r)
    {
        int t=a[l];
        a[l]=a[r];
        a[r]=t;
        l++;
        r--;
    }

    l=0,r=k-1;
    while(l<r)
    {
        int t=a[l];
        a[l]=a[r];
        a[r]=t;
        l++;
        r--;
    }

    l=k,r=n-1;
    while(l<r)
    {
        int t=a[l];
        a[l]=a[r];
        a[r]=t;
        l++;
        r--;
    }

    printf("Array after rotation: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}