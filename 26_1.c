#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *prev,*next;
};

int main()
{
    int n1,x;

    printf("Enter number of nodes: ");
    scanf("%d",&n1);

    struct n *h=NULL,*t=NULL;

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->prev=NULL;
        p->next=NULL;

        if(h==NULL)
        {
            h=p;
            t=p;
        }
        else
        {
            t->next=p;
            p->prev=t;
            t=p;
        }
    }

    printf("Forward: ");
    struct n *p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    printf("\nBackward: ");
    p=t;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->prev;
    }

    return 0;
}