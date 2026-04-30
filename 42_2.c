#include <stdio.h>
#include <stdlib.h>

struct n
{
    int d;
    struct n *l,*r;
};

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

    printf("Inorder: ");
    inorder(nodes[0]);

    return 0;
}