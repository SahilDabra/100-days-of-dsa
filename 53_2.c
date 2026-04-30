#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d,h;
    struct n *l,*r;
};

int height(struct n *root)
{
    if(root==NULL)
        return 0;

    return root->h;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

struct n* newnode(int x)
{
    struct n *p=(struct n*)malloc(sizeof(struct n));
    p->d=x;
    p->l=NULL;
    p->r=NULL;
    p->h=1;
    return p;
}

struct n* rightrotate(struct n *y)
{
    struct n *x=y->l;
    struct n *t=x->r;

    x->r=y;
    y->l=t;

    y->h=max(height(y->l),height(y->r))+1;
    x->h=max(height(x->l),height(x->r))+1;

    return x;
}

struct n* leftrotate(struct n *x)
{
    struct n *y=x->r;
    struct n *t=y->l;

    y->l=x;
    x->r=t;

    x->h=max(height(x->l),height(x->r))+1;
    y->h=max(height(y->l),height(y->r))+1;

    return y;
}

int balance(struct n *root)
{
    if(root==NULL)
        return 0;

    return height(root->l)-height(root->r);
}

struct n* minnode(struct n *root)
{
    while(root->l!=NULL)
        root=root->l;

    return root;
}

struct n* insert(struct n *root,int x)
{
    if(root==NULL)
        return newnode(x);

    if(x < root->d)
        root->l=insert(root->l,x);
    else
        root->r=insert(root->r,x);

    root->h=1+max(height(root->l),height(root->r));

    int b=balance(root);

    if(b>1 && x < root->l->d)
        return rightrotate(root);

    if(b<-1 && x > root->r->d)
        return leftrotate(root);

    if(b>1 && x > root->l->d)
    {
        root->l=leftrotate(root->l);
        return rightrotate(root);
    }

    if(b<-1 && x < root->r->d)
    {
        root->r=rightrotate(root->r);
        return leftrotate(root);
    }

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
        if(root->l==NULL || root->r==NULL)
        {
            struct n *temp;

            if(root->l!=NULL)
                temp=root->l;
            else
                temp=root->r;

            if(temp==NULL)
                return NULL;
            else
                *root=*temp;
        }
        else
        {
            struct n *temp=minnode(root->r);
            root->d=temp->d;
            root->r=delete(root->r,temp->d);
        }
    }

    root->h=1+max(height(root->l),height(root->r));

    int b=balance(root);

    if(b>1 && balance(root->l)>=0)
        return rightrotate(root);

    if(b>1 && balance(root->l)<0)
    {
        root->l=leftrotate(root->l);
        return rightrotate(root);
    }

    if(b<-1 && balance(root->r)<=0)
        return leftrotate(root);

    if(b<-1 && balance(root->r)>0)
    {
        root->r=rightrotate(root->r);
        return leftrotate(root);
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