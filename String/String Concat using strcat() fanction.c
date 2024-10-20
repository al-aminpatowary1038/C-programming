#include<stdio.h>
#include<conio.h>
int main()
{
    char s1[100],s2[100];
    printf("Enter First Word: ");
    gets(s1);
    printf("Enter Second Word: ");
    gets(s2);
    strcat(s1,s2);
    printf("String: %s\n",s1);
    getch();
}
