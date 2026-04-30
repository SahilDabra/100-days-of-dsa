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

    struct n *prev=NULL,*cur=h,*next;

    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }

    h=prev;

    printf("Reversed list: ");

    struct n *p=h;
    while(p!=NULL)
    {
        printf("%d ",p->d);
        p=p->next;
    }

    return 0;
}