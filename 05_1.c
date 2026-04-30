#include <stdio.h>

int main()
{
    int n1,n2,a[100],b[100],c[200];

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

    int i=0,j=0,k=0;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }

    while(i<n1)
        c[k++]=a[i++];

    while(j<n2)
        c[k++]=b[j++];

    printf("Merged array: ");
    for(int i=0;i<k;i++)
        printf("%d ",c[i]);

    return 0;
}