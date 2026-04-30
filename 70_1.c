#include <stdio.h>

int a[100],n,target;

void solve(int i,int sum,int res[],int size)
{
    if(sum==target)
    {
        for(int j=0;j<size;j++)
            printf("%d ",res[j]);
        printf("\n");
        return;
    }

    if(sum>target || i>=n)
        return;

    // include (reuse allowed)
    res[size]=a[i];
    solve(i,sum+a[i],res,size+1);

    // exclude
    solve(i+1,sum,res,size);
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

    int res[100];

    solve(0,0,res,0);

    return 0;
}