#include <stdio.h>

int main()
{
    int n,k,a[100],c=0,pos=-1;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter element to search: ");
    scanf("%d",&k);

    for(int i=0;i<n;i++)
    {
        c++;
        if(a[i]==k)
        {
            pos=i;
            break;
        }
    }

    if(pos!=-1)
        printf("Found at index: %d\n",pos);
    else
        printf("Element not found\n");

    printf("Comparisons: %d",c);

    return 0;
}