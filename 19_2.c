#include <stdio.h>

int main()
{
    int n,a[100];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int max=a[0],cur_max=a[0];
    int min=a[0],cur_min=a[0];
    int sum=a[0];

    for(int i=1;i<n;i++)
    {
        if(cur_max + a[i] > a[i])
            cur_max = cur_max + a[i];
        else
            cur_max = a[i];

        if(cur_max > max)
            max = cur_max;

        if(cur_min + a[i] < a[i])
            cur_min = cur_min + a[i];
        else
            cur_min = a[i];

        if(cur_min < min)
            min = cur_min;

        sum += a[i];
    }

    int circular = sum - min;

    if(max < 0)
        printf("Maximum circular sum: %d",max);
    else if(circular > max)
        printf("Maximum circular sum: %d",circular);
    else
        printf("Maximum circular sum: %d",max);

    return 0;
}