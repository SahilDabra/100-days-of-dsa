#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *next;
};

int main()
{
    int n1,x,a[100];

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

        a[i]=x;

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

    int l=0,r=n1-1,flag=1;

    while(l<r)
    {
        if(a[l]!=a[r])
        {
            flag=0;
            break;
        }
        l++;
        r--;
    }

    if(flag)
        printf("Palindrome");
    else
        printf("Not palindrome");

    return 0;
}