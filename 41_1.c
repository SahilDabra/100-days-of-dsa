#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *next;
};

int main()
{
    int n1,x;

    printf("Enter number of elements: ");
    scanf("%d",&n1);

    struct n *front=NULL,*rear=NULL;

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->next=NULL;

        if(front==NULL)
        {
            front=p;
            rear=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
    }

    printf("Queue: ");
    struct n *p=front;

    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    if(front==NULL)
    {
        printf("\nQueue underflow");
    }
    else
    {
        front=front->next;
    }

    printf("\nAfter deletion: ");
    p=front;

    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    return 0;
}