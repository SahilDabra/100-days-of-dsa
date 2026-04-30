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

    printf("Enter number of elements: ");
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

    printf("List: ");
    struct n *p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    struct n *nf=(struct n*)malloc(sizeof(struct n));
    nf->d=5;
    nf->prev=NULL;
    nf->next=h;
    if(h!=NULL)
        h->prev=nf;
    h=nf;

    printf("\nAfter insert front: ");
    p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    struct n *ne=(struct n*)malloc(sizeof(struct n));
    ne->d=40;
    ne->next=NULL;
    ne->prev=t;
    if(t!=NULL)
        t->next=ne;
    t=ne;

    printf("\nAfter insert end: ");
    p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    if(h!=NULL)
    {
        h=h->next;
        if(h!=NULL)
            h->prev=NULL;
    }

    printf("\nAfter delete front: ");
    p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    if(t!=NULL)
    {
        t=t->prev;
        if(t!=NULL)
            t->next=NULL;
    }

    printf("\nAfter delete end: ");
    p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    return 0;
}