#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *next;
};

int main()
{
    int v,e,u,w;

    printf("Enter number of vertices: ");
    scanf("%d",&v);

    struct n *a[100];

    for(int i=0;i<v;i++)
        a[i]=NULL;

    printf("Enter number of edges: ");
    scanf("%d",&e);

    printf("Enter edges:\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&w);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=w;
        p->next=a[u];
        a[u]=p;

        struct n *q=(struct n*)malloc(sizeof(struct n));
        q->d=u;
        q->next=a[w];
        a[w]=q;
    }

    for(int i=0;i<v;i++)
    {
        printf("%d: ",i);

        struct n *p=a[i];

        while(p!=NULL)
        {
            printf("%d ",p->d);
            p=p->next;
        }

        printf("\n");
    }

    return 0;
}