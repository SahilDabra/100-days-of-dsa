#include <stdio.h>

int main()
{
    int n;
    char s[100];

    printf("Enter number of characters: ");
    scanf("%d",&n);

    printf("Enter characters one by one: ");
    for(int i=0;i<n;i++)
        scanf(" %c",&s[i]);

    int l=0,r=n-1;

    while(l<r)
    {
        char t=s[l];
        s[l]=s[r];
        s[r]=t;

        l++;
        r--;
    }

    printf("Reversed string: ");
    for(int i=0;i<n;i++)
        printf("%c",s[i]);

    return 0;
}