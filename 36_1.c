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

        rear = (rear + 1) % 100;
        a[rear] = x;
    }

    printf("Queue: ");

    int i = front;

    while(1)
    {
        printf("%d ",a[i]);

        if(i == rear)
            break;

        i = (i + 1) % 100;
    }

    if(front == (rear + 1) % 100)
    {
        printf("\nQueue underflow");
    }
    else
    {
        front = (front + 1) % 100;
    }

    printf("\nAfter deletion: ");

    i = front;

    while(1)
    {
        printf("%d ",a[i]);

        if(i == rear)
            break;

        i = (i + 1) % 100;
    }

    return 0;
}