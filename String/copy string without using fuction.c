#include<stdio.h>
#include<conio.h>
 void StringCopy(char s1[1000], char s2[1000])
{
     for(int i=0;i<s1[i]!='\0';i++)
    {
        s2[i]=s1[i];
        s2[i+1]= '\0';
    }

    printf("First String: %s\n",s1);
    printf("Second String: %s\n",s2);
}
int main()
{
    char s1[1000],s2[1000];
    printf("Enter any Word: ");
    gets(s1);
    StringCopy(s1,s2);
     getch();
}
