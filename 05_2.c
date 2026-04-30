#include <stdio.h>

int main()
{
    int m,n,a[200],b[100];
    printf("Enter size of first array: ");
    scanf("%d",&m);
    printf("Enter elements of first array: ");
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    printf("Enter size of second array: ");
    scanf("%d",&n);
    printf("Enter elements of second array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0 && j>=0)
    {
        if(a[i]>b[j])
            a[k--]=a[i--];
        else
            a[k--]=b[j--];
    }
    while(j>=0)
        a[k--]=b[j--];
    printf("Merged array: ");
    for(int i=0;i<m+n;i++)
        printf("%d ",a[i]);
    return 0;
}