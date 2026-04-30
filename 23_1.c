#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *next;
};

int main()
{
    int n1,n2,x;

    printf("Enter number of nodes of first list: ");
    scanf("%d",&n1);

    struct n *h1=NULL,*t1=NULL;

    printf("Enter elements of first list: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->next=NULL;

        if(h1==NULL)
        {
            h1=p;
            t1=p;
        }
        else
        {
            t1->next=p;
            t1=p;
        }
    }

    printf("Enter number of nodes of second list: ");
    scanf("%d",&n2);

    struct n *h2=NULL,*t2=NULL;

    printf("Enter elements of second list: ");
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&x);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->next=NULL;

        if(h2==NULL)
        {
            h2=p;
            t2=p;
        }
        else
        {
            t2->next=p;
            t2=p;
        }
    }

    struct n *h=NULL,*t=NULL;

    while(h1!=NULL && h2!=NULL)
    {
        struct n *p;

        if(h1->d < h2->d)
        {
            p=h1;
            h1=h1->next;
        }
        else
        {
            p=h2;
            h2=h2->next;
        }

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

    if(h1!=NULL)
        t->next=h1;

    if(h2!=NULL)
        t->next=h2;

    printf("Merged list: ");

    struct n *p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    return 0;
}