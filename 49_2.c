#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *l,*r;
};

struct n* lca(struct n *root,int a,int b)
{
    if(root==NULL)
        return NULL;

    if(root->d==a || root->d==b)
        return root;

    struct n *l=lca(root->l,a,b);
    struct n *r=lca(root->r,a,b);

    if(l!=NULL && r!=NULL)
        return root;

    if(l!=NULL)
        return l;
    else
        return r;
}

int main()
{
    int n1,a[100],x,y;

    printf("Enter number of nodes: ");
    scanf("%d",&n1);

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter two values: ");
    scanf("%d%d",&x,&y);

    struct n *nodes[100];

    for(int i=0;i<n1;i++)
    {
        if(a[i]==-1)
            nodes[i]=NULL;
        else
        {
            nodes[i]=(struct n*)malloc(sizeof(struct n));
            nodes[i]->d=a[i];
            nodes[i]->l=NULL;
            nodes[i]->r=NULL;
        }
    }

    for(int i=0;i<n1;i++)
    {
        if(nodes[i]!=NULL)
        {
            int li=2*i+1;
            int ri=2*i+2;

            if(li<n1)
                nodes[i]->l=nodes[li];

            if(ri<n1)
                nodes[i]->r=nodes[ri];
        }
    }

    struct n *res=lca(nodes[0],x,y);

    if(res!=NULL)
        printf("LCA: %d",res->d);
    else
        printf("Not found");

    return 0;
}