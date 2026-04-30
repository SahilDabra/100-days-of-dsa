#include <stdio.h>
#include <stdlib.h>

struct n
{
    int c,p;
    struct n *next;
};

int main()
{
    int n1,n2,c1,p1;

    printf("Enter number of terms of first polynomial: ");
    scanf("%d",&n1);

    struct n *h1=NULL,*t1=NULL;

    printf("Enter coefficient and power:\n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d%d",&c1,&p1);

        struct n *node=(struct n*)malloc(sizeof(struct n));
        node->c=c1;
        node->p=p1;
        node->next=NULL;

        if(h1==NULL)
        {
            h1=node;
            t1=node;
        }
        else
        {
            t1->next=node;
            t1=node;
        }
    }

    printf("Enter number of terms of second polynomial: ");
    scanf("%d",&n2);

    struct n *h2=NULL,*t2=NULL;

    printf("Enter coefficient and power:\n");
    for(int i=0;i<n2;i++)
    {
        scanf("%d%d",&c1,&p1);

        struct n *node=(struct n*)malloc(sizeof(struct n));
        node->c=c1;
        node->p=p1;
        node->next=NULL;

        if(h2==NULL)
        {
            h2=node;
            t2=node;
        }
        else
        {
            t2->next=node;
            t2=node;
        }
    }

    struct n *h=NULL,*t=NULL;

    while(h1!=NULL && h2!=NULL)
    {
        struct n *node=(struct n*)malloc(sizeof(struct n));

        if(h1->p == h2->p)
        {
            node->c = h1->c + h2->c;
            node->p = h1->p;
            h1 = h1->next;
            h2 = h2->next;
        }
        else if(h1->p > h2->p)
        {
            node->c = h1->c;
            node->p = h1->p;
            h1 = h1->next;
        }
        else
        {
            node->c = h2->c;
            node->p = h2->p;
            h2 = h2->next;
        }

        node->next=NULL;

        if(h==NULL)
        {
            h=node;
            t=node;
        }
        else
        {
            t->next=node;
            t=node;
        }
    }

    while(h1!=NULL)
    {
        struct n *node=(struct n*)malloc(sizeof(struct n));
        node->c=h1->c;
        node->p=h1->p;
        node->next=NULL;

        if(h==NULL)
        {
            h=node;
            t=node;
        }
        else
        {
            t->next=node;
            t=node;
        }

        h1=h1->next;
    }

    while(h2!=NULL)
    {
        struct n *node=(struct n*)malloc(sizeof(struct n));
        node->c=h2->c;
        node->p=h2->p;
        node->next=NULL;

        if(h==NULL)
        {
            h=node;
            t=node;
        }
        else
        {
            t->next=node;
            t=node;
        }

        h2=h2->next;
    }

    printf("Result: ");

    struct n *p=h;

    while(p!=NULL)
    {
        printf("%dx^%d",p->c,p->p);

        if(p->next!=NULL)
            printf(" + ");

        p=p->next;
    }

    return 0;
}