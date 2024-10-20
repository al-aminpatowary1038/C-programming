#include<stdio.h>
#include<conio.h>
void StringCopy(char S1[1000],char S2[1000])
{
    int len=0,i=0;
    for(i=0;i<S1[i]!='\0';i++)
    {
        len++;
    }
    for(i=0;i<S2 [i]!='\0';i++)
    {
        S1[len+i]=S2[i];
        S1[len+i+1]='\0';
    }
    printf("String: %s",S1);
}
int main()
{
    char s1[100],s2[100];
    printf("Enter First String: ");
    gets(s1);
    printf("Enter Second String: ");
    gets(s2);
    StringCopy(s1,s2);
    getch();
}
