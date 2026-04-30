#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of days: ");
    scanf("%d",&n);

    printf("Enter prices of each day: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int min=a[0],profit=0;

    for(int i=1;i<n;i++)
    {
        if(a[i]<min)
            min=a[i];
        else if(a[i]-min>profit)
            profit=a[i]-min;
    }

    printf("Maximum profit: %d",profit);

    return 0;
}