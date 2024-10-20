#include<stdio.h>
#include<conio.h>


void SwapString(char s1[],char s2[])
{
    char temp[10000];
    for(int i=0;i<s1[i]!='\0';i++)
    {
        temp[i]=s1[i];
        temp[i+1]='\0';
    }
    for(int i=0;i<s2[i]!='\0';i++)
    {
        s1[i]=s2[i];
        s1[i+1]='\0';
    }
    for(int i=0;i<temp[i]!='\0';i++)
    {
        s2[i]=temp[i];
        s2[i+1]='\0';
    }
     printf("\nAfter Swapping Strings:\n");
     printf("First String: %s\n",s1);
     printf("Second String: %s\n",s2);
}

int main()
{
    char st1[10000],st2[10000];
    printf("Enter First String: ");
    gets(st1);
    printf("Enter Second String: ");
    gets(st2);
    SwapString(st1,st2);
    getch();
}
