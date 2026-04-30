#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *next;
};

int main()
{
    int n1,x,pos;

    printf("Enter number of nodes: ");
    scanf("%d",&n1);

    struct n *h=NULL,*t=NULL,*arr[100];

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);

        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->next=NULL;

        arr[i]=p;

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

    printf("Enter position to create cycle (0 for no cycle): ");
    scanf("%d",&pos);

    if(pos>0 && pos<=n1)
        t->next = arr[pos-1];

    struct n *slow=h,*fast=h;

    int flag=0;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("No cycle");
        return 0;
    }

    slow=h;

    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }

    printf("Cycle starts at: %d",slow->d);

    return 0;
}