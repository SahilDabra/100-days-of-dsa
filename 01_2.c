#include <stdio.h>

int main()
{
    int n,t,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter target value: ");
    scanf("%d",&t);

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==t)
            {
                printf("Indices: %d %d",i,j);
                return 0;
            }
        }
    }

    printf("No solution");
    return 0;
}