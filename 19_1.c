#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int min_sum = a[0] + a[1];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int s = a[i] + a[j];

            if(s<0 && -s < (min_sum<0 ? -min_sum : min_sum))
                min_sum = s;

            if(s>=0 && s < (min_sum<0 ? -min_sum : min_sum))
                min_sum = s;
        }
    }

    printf("Closest sum: %d",min_sum);

    return 0;
}