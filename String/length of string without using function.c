#include<stdio.h>
#include<conio.h>
int Length(char s[100]) //User Define function
{
    int i=0,len=0;
    for(i=0;i<s[i]!='\0';i++)
    {
        len++;
    }
    return len;
}
int main()
{
    char s1[100];
    printf("Enter any Word: ");
    gets(s1);
    int len = Length(s1);
    printf("Length = %d\n",len);
    getch();
}
