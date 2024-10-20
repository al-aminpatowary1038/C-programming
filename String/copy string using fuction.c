#include<stdio.h>
#include<conio.h>
int main()
{
    char s1[100],s2[100];
    printf("Enter Any Word: ");
    gets(s1);
    strcpy(s2,s1);
    printf("First String: %s\n",s1);
    printf("Second String: %s\n",s2);
    getch();
}
