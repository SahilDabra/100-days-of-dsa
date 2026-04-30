#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *next;
};

int main()
{
    int n1,x,k;

    printf("Enter number of nodes: ");
    scanf("%d",&n1);

    struct n *h=NULL,*t=NULL;

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->next=NULL;

        if(h==NULL)
        {
            h=p;
            t=p;
        }
        else
        {
            t->next=p;
            t=p;
        }
    }

    printf("Enter value of k: ");
    scanf("%d",&k);

    int len=0;
    struct n *p=h;

    while(p!=NULL)
    {
        len++;
        p=p->next;
    }

    if(len==0)
        return 0;

    k = k % len;

    if(k==0)
    {
        printf("Rotated list: ");
        p=h;
        while(p!=NULL)
        {
            printf("%d ",p->d);
            p=p->next;
        }
        return 0;
    }

    t->next=h;

    int steps = len - k;

    p=h;

    for(int i=1;i<steps;i++)
        p=p->next;

    h=p->next;
    p->next=NULL;

    printf("Rotated list: ");
    p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    return 0;
}