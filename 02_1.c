#include <stdio.h>

int main()
{
    int n,p,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter position to delete:");
    scanf("%d",&p);

    for(int i=p-1;i<n-1;i++)
        a[i]=a[i+1];

    printf("Array after deletion: ");
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);

    return 0;
}