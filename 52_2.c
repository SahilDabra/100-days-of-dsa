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

void range(struct n *root,int L,int R)
{
    if(root==NULL)
        return;

    if(root->d > L)
        range(root->l,L,R);

    if(root->d >= L && root->d <= R)
        printf("%d ",root->d);

    if(root->d < R)
        range(root->r,L,R);
}

void inorder(struct n *root)
{
    if(root==NULL)
        return;

    inorder(root->l);
    printf("%d ",root->d);
    inorder(root->r);
}

int main()
{
    int n1,x,L,R;

    printf("Enter number of elements: ");
    scanf("%d",&n1);

    struct n *root=NULL;

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }

    printf("Enter L and R: ");
    scanf("%d%d",&L,&R);

    printf("Elements in range: ");
    range(root,L,R);

    return 0;
}