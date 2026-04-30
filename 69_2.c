#include <stdio.h>

int a[100],n;

void subset(int i,int res[],int size)
{
    if(i==n)
    {
        printf("{ ");
        for(int j=0;j<size;j++)
        {
            printf("%d ",res[j]);
        }
        printf("}\n");
        return;
    }

    // include
    res[size]=a[i];
    subset(i+1,res,size+1);

    // exclude
    subset(i+1,res,size);
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

    int res[100];

    subset(0,res,0);

    return 0;
}