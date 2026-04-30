#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Result: ");

    for(int i=0;i<n;i++)
    {
        int prod=1;

        for(int j=0;j<n;j++)
        {
            if(i!=j)
                prod = prod * a[j];
        }

        printf("%d ",prod);
    }

    return 0;
}