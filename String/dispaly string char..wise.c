#include<stdio.h>
#include<conio.h>
int main()
{
    char s1[1000];
    printf("Enter a word: ");
    gets(s1);
    for(int i=0;i<s1[i]!='\0';i++)
    {
        printf("%c\n",s1[i]);
    }
     getch();
}
