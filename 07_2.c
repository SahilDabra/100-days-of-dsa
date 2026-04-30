#include <stdio.h>

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    if(n<=1)
    {
        printf("Fibonacci number: %d",n);
        return 0;
    }

    int p2=0,p1=1,c;

    for(int i=2;i<=n;i++)
    {
        c=p1+p2;
        p2=p1;
        p1=c;
    }

    printf("Fibonacci number: %d",p1);

    return 0;
}