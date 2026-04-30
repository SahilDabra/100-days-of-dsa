#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *l,*r;
};

int height(struct n *root)
{
    if(root==NULL)
        return 0;

    int l=height(root->l);
    int r=height(root->r);

    if(l>r)
        return l+1;
    else
        return r+1;
}

int check(struct n *root)
{
    if(root==NULL)
        return 1;

    int l=height(root->l);
    int r=height(root->r);

    if(l-r>1 || r-l>1)
        return 0;

    return check(root->l) && check(root->r);
}

int main()
{
    int n1,a[100];

    printf("Enter number of nodes: ");
    scanf("%d",&n1);

    printf("Enter elements: ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }

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

    if(check(nodes[0]))
        printf("Balanced tree");
    else
        printf("Not balanced");

    return 0;
}