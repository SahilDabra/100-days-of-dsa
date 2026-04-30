#include <stdio.h>

struct act
{
    int s,f;
};

int main()
{
    int n;

    printf("Enter number of activities: ");
    scanf("%d",&n);

    struct act a[100],temp;

    printf("Enter start times: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].s);
    }

    printf("Enter finish times: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].f);
    }

    // sort by finish time
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].f > a[j].f)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    int count=1;
    int last=a[0].f;

    for(int i=1;i<n;i++)
    {
        if(a[i].s >= last)
        {
            count++;
            last=a[i].f;
        }
    }

    printf("Maximum activities: %d",count);

    return 0;
}