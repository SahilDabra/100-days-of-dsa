#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int count=0;

    for(int i=0;i<n;i++)
    {
        int sum=0;

        for(int j=i;j<n;j++)
        {
            sum = sum + a[j];

            if(sum==0)
                count++;
        }
    }

    printf("Count: %d",count);

    return 0;
}