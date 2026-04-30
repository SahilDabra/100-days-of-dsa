#include <stdio.h>

int main()
{
    int n,s1[100],s2[100],top1=-1,top2=-1,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        top1++;
        s1[top1]=x;
    }

    printf("Queue: ");
    for(int i=0;i<=top1;i++)
    {
        printf("%d ",s1[i]);
    }

    if(top1==-1)
    {
        printf("\nQueue underflow");
    }
    else
    {
        while(top1!=-1)
        {
            top2++;
            s2[top2]=s1[top1];
            top1--;
        }

        top2--;

        while(top2!=-1)
        {
            top1++;
            s1[top1]=s2[top2];
            top2--;
        }
    }

    printf("\nAfter deletion: ");
    for(int i=0;i<=top1;i++)
    {
        printf("%d ",s1[i]);
    }

    return 0;
}