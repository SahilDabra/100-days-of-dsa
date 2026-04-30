#include <stdio.h>

int main()
{
    int a[100],front=0,rear=-1,n,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        rear++;
        a[rear]=x;
    }

    printf("Deque: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }

    front--;
    a[front]=5;

    printf("\nAfter insert front: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }

    rear++;
    a[rear]=40;

    printf("\nAfter insert rear: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }

    front++;

    printf("\nAfter delete front: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }

    rear--;

    printf("\nAfter delete rear: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}