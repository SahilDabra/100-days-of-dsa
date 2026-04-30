#include <stdio.h>

int main()
{
    int n;

    printf("Enter number: ");
    scanf("%d",&n);

    if(n>0 && (n & (n-1))==0)
        printf("Yes, it is a power of 2");
    else
        printf("No, it is not a power of 2");

    return 0;
}