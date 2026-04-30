#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[100];
    int st[100],top=-1;

    printf("Enter postfix expression: ");
    scanf("%s",s);

    for(int i=0;s[i]!='\0';i++)
    {
        if(isdigit(s[i]))
        {
            st[++top]=s[i]-'0';
        }
        else
        {
            int b=st[top--];
            int a=st[top--];

            if(s[i]=='+') st[++top]=a+b;
            else if(s[i]=='-') st[++top]=a-b;
            else if(s[i]=='*') st[++top]=a*b;
            else if(s[i]=='/') st[++top]=a/b;
        }
    }

    printf("Result: %d",st[top]);

    return 0;
}