#include <stdio.h>
#include <stdlib.h>

struct n
{
    int c,p;
    struct n *next;
};

int main()
{
    int n1,c1,p1;

    printf("Enter number of terms: ");
    scanf("%d",&n1);

    struct n *h=NULL,*t=NULL;

    printf("Enter coefficient and power:\n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d%d",&c1,&p1);

        struct n *node=(struct n*)malloc(sizeof(struct n));
        node->c=c1;
        node->p=p1;
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

    printf("Polynomial: ");

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