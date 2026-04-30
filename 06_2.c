#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int j=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            j++;
        }
    }

    printf("Array after moving zeroes: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}