#include <stdio.h>

int main()
{
    int n,a[100],top=-1,x,min;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        top++;
        a[top]=x;

        if(i==0)
            min=x;
        else if(x<min)
            min=x;
    }

    printf("Stack: ");
    for(int i=0;i<=top;i++)
        printf("%d ",a[i]);

    printf("\nMinimum element: %d",min);

    return 0;
}