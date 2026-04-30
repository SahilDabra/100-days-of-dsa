#include <stdio.h>

int main()
{
    int n,a[100],val;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter value to remove: ");
    scanf("%d",&val);

    int j=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]!=val)
        {
            a[j]=a[i];
            j++;
        }
    }

    printf("Array after removal: ");
    for(int i=0;i<j;i++)
        printf("%d ",a[i]);

    return 0;
}