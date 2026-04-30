#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *l,*r;
};

int main()
{
    int n1,x,i=0;

    printf("Enter number of nodes: ");
    scanf("%d",&n1);

    int a[100];

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }

    struct n *root=NULL;

    if(a[0]!=-1)
    {
        root=(struct n*)malloc(sizeof(struct n));
        root->d=a[0];
        root->l=NULL;
        root->r=NULL;
    }

    struct n *q[100];
    int front=0,rear=0;

    if(root!=NULL)
    {
        q[rear]=root;
    }

    while(front<=rear && i<n1)
    {
        struct n *temp=q[front];
        front++;

        int li=2*i+1;
        int ri=2*i+2;

        if(li<n1 && a[li]!=-1)
        {
            temp->l=(struct n*)malloc(sizeof(struct n));
            temp->l->d=a[li];
            temp->l->l=NULL;
            temp->l->r=NULL;

            rear++;
            q[rear]=temp->l;
        }

        if(ri<n1 && a[ri]!=-1)
        {
            temp->r=(struct n*)malloc(sizeof(struct n));
            temp->r->d=a[ri];
            temp->r->l=NULL;
            temp->r->r=NULL;

            rear++;
            q[rear]=temp->r;
        }

        i++;
    }

    printf("Level order: ");

    while(front<=rear)
    {
        printf("%d ",q[front]->d);
        front++;
    }

    return 0;
}