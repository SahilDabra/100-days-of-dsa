#include <stdio.h>

struct job
{
    int d,p;
};

int main()
{
    int n;

    printf("Enter number of jobs: ");
    scanf("%d",&n);

    struct job a[100],temp;

    printf("Enter deadline and profit:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].d,&a[i].p);
    }

    // sort by profit (descending)
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].p < a[j].p)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    int slot[100]={0};
    int profit=0;

    for(int i=0;i<n;i++)
    {
        for(int j=a[i].d;j>0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=1;
                profit+=a[i].p;
                break;
            }
        }
    }

    printf("Maximum profit: %d",profit);

    return 0;
}