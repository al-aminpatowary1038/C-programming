#include<stdio.h>
#include<conio.h>
int main()
{
    char s1[10000],s2[10000];
    printf("Enter First String: ");
    gets(s1);
    printf("Enter Second String: ");
    gets(s2);
    int a = strcmp(s1,s2);
    if(a==0)
    {
        printf("Strings are Same");
    }
    else
    {
        printf("Strings are not Same");
    }
    getch();
}
