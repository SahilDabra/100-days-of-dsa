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

struct n* minnode(struct n *root)
{
    while(root->l!=NULL)
        root=root->l;

    return root;
}

struct n* delete(struct n *root,int x)
{
    if(root==NULL)
        return NULL;

    if(x < root->d)
        root->l=delete(root->l,x);
    else if(x > root->d)
        root->r=delete(root->r,x);
    else
    {
        if(root->l==NULL)
            return root->r;
        else if(root->r==NULL)
            return root->l;

        struct n *temp=minnode(root->r);
        root->d=temp->d;
        root->r=delete(root->r,temp->d);
    }

    return root;
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

    printf("Enter value to delete: ");
    scanf("%d",&key);

    root=delete(root,key);

    printf("Inorder: ");
    inorder(root);

    return 0;
}