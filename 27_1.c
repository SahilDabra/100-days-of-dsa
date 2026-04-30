#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *next;
};

int main()
{
    int n1,n2,x,pos;

    printf("Enter number of nodes of first list: ");
    scanf("%d",&n1);

    struct n *h1=NULL,*t1=NULL,*arr[100];

    printf("Enter elements of first list: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->next=NULL;

        arr[i]=p;

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

    printf("Enter position to connect: ");
    scanf("%d",&pos);

    if(pos>0 && pos<=n1)
        t2->next = arr[pos-1];

    struct n *p1=h1,*p2=h2;

    while(p1!=NULL)
    {
        p2=h2;
        while(p2!=NULL)
        {
            if(p1==p2)
            {
                printf("Intersection at: %d",p1->d);
                return 0;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }

    printf("No intersection");

    return 0;
}