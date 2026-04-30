#include <stdio.h>

int main()
{
    int n,a[100],top=-1,x;

    printf("Enter number of elements to push: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        top++;
        a[top]=x;
    }

    printf("Stack: ");
    for(int i=0;i<=top;i++)
        printf("%d ",a[i]);

    if(top==-1)
        printf("\nStack underflow");
    else
    {
        printf("\nPopped element: %d",a[top]);
        top--;
    }

    printf("\nStack after pop: ");
    for(int i=0;i<=top;i++)
        printf("%d ",a[i]);

    return 0;
}