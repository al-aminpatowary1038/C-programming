//Write a C program to check whether a string is palindrome or not.
#include<stdio.h>
#include<conio.h>

int Palindrome(char s1[])
{
    int i=0,j=0,length=0;
    for(i=0;i<s1[i]!='\0';i++)
    {
        length++;
    }
    char s2[10000];
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        s2[j]=s1[i];
        s2[j+1]='\0';
    }
    int p = strcmp(s1,s2);
    return p;
}

int main()
{
    char str[10000];
    printf("Enter a String: ");
    gets(str);
    int p =Palindrome(str);
    if(p==0)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    getch();
}
