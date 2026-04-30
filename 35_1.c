#include <stdio.h>

int main()
{
    int n,a[100],front=0,rear=-1,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        rear++;
        a[rear]=x;
    }

    printf("Queue: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }

    if(front>rear)
    {
        printf("\nQueue underflow");
    }
    else
    {
        front++;
    }

    printf("\nAfter deletion: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}