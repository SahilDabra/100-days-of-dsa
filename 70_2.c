#include <stdio.h>

int a[100],n,target;

void sort()
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void solve(int start,int sum,int res[],int size)
{
    if(sum==target)
    {
        for(int i=0;i<size;i++)
            printf("%d ",res[i]);
        printf("\n");
        return;
    }

    for(int i=start;i<n;i++)
    {
        if(i>start && a[i]==a[i-1])
            continue;

        if(sum+a[i]>target)
            break;

        res[size]=a[i];

        solve(i+1,sum+a[i],res,size+1);
    }
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter target: ");
    scanf("%d",&target);

    sort();

    int res[100];

    solve(0,0,res,0);

    return 0;
}