#include <stdio.h>

int main()
{
    int n,p,x,a[100];

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter the position (1-based): ");
    scanf("%d",&p);

    printf("Enter the element to insert: ");
    scanf("%d",&x);

    for(int i=n-1;i>=p-1;i--)
        a[i+1]=a[i];

    a[p-1]=x;

    printf("Array after insertion: ");
    for(int i=0;i<=n;i++)
        printf("%d ",a[i]);

    return 0;
}