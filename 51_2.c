#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *l,*r;
};

struct n* insert(struct n *root,int x)
{
    if(root==NULL)
    {
        struct n *p=(struct n*)malloc(sizeof(struct n));
        p->d=x;
        p->l=NULL;
        p->r=NULL;
        return p;
    }

    if(x < root->d)
        root->l=insert(root->l,x);
    else
        root->r=insert(root->r,x);

    return root;
}

int search(struct n *root,int x)
{
    if(root==NULL)
        return 0;

    if(root->d==x)
        return 1;

    if(x < root->d)
        return search(root->l,x);
    else
        return search(root->r,x);
}

int main()
{
    int n1,x,key;

    printf("Enter number of elements: ");
    scanf("%d",&n1);

    struct n *root=NULL;

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }

    printf("Enter value to search: ");
    scanf("%d",&key);

    if(search(root,key))
        printf("Element found");
    else
        printf("Element not found");

    return 0;
}