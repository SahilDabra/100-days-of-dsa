#include <stdio.h>

int main()
{
    int n,q[100],s[100],front=0,rear=-1,top=-1,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        rear++;
        q[rear]=x;
    }

    for(int i=front;i<=rear;i++)
    {
        top++;
        s[top]=q[i];
    }

    rear=-1;

    while(top!=-1)
    {
        rear++;
        q[rear]=s[top];
        top--;
    }

    printf("Reversed queue: ");
    for(int i=0;i<=rear;i++)
    {
        printf("%d ",q[i]);
    }

    return 0;
}