#include <stdio.h>

int main()
{
    int n1,n2,a[100],b[100];

    printf("Enter size of first array: ");
    scanf("%d",&n1);

    printf("Enter elements of first array: ");
    for(int i=0;i<n1;i++)
        scanf("%d",&a[i]);

    printf("Enter size of second array: ");
    scanf("%d",&n2);

    printf("Enter elements of second array: ");
    for(int i=0;i<n2;i++)
        scanf("%d",&b[i]);

    printf("Intersection: ");

    for(int i=0;i<n1;i++)
    {
        int found=0;

        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                found=1;
                break;
            }
        }

        if(found) continue;

        for(int j=0;j<n2;j++)
        {
            if(a[i]==b[j])
            {
                printf("%d ",a[i]);
                break;
            }
        }
    }

    return 0;
}