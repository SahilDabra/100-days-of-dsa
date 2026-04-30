#include <stdio.h>
#include <ctype.h>

int pr(char ch)
{
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 2;
    return 0;
}

int main()
{
    char s[100],st[100],res[100];
    int top=-1,k=0;

    printf("Enter infix expression: ");
    scanf("%s",s);

    for(int i=0;s[i]!='\0';i++)
    {
        if(isalnum(s[i]))
            res[k++]=s[i];

        else if(s[i]=='(')
            st[++top]=s[i];

        else if(s[i]==')')
        {
            while(top!=-1 && st[top]!='(')
                res[k++]=st[top--];
            top--;
        }

        else
        {
            while(top!=-1 && pr(st[top])>=pr(s[i]))
                res[k++]=st[top--];
            st[++top]=s[i];
        }
    }

    while(top!=-1)
        res[k++]=st[top--];

    res[k]='\0';

    printf("Postfix expression: %s",res);

    return 0;
}