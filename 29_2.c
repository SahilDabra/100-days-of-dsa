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

    printf("Enter digits of first number: ");
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

    printf("Enter digits of second number: ");
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

    int carry=0;

    while(h1!=NULL || h2!=NULL || carry!=0)
    {
        int sum=carry;

        if(h1!=NULL)
        {
            sum += h1->d;
            h1=h1->next;
        }

        if(h2!=NULL)
        {
            sum += h2->d;
            h2=h2->next;
        }

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d = sum % 10;
        p->next=NULL;

        carry = sum / 10;

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

    printf("Result: ");
    struct n *p=h;

    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    return 0;
}