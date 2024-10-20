#include<stdio.h>
#include<conio.h>

 void ReverseString(char s1[],char s2[])
 {
     int i=0,len=0,j=0;
     for(i=0;i,s1[i]!='\0';i++)
     {
         len++;
     }
     for(i=len-1,j=0; i>=0;i--,j++)
     {
         s2[j]=s1[i];
     }
     printf("Reverse String: %s",s2);
 }

int main()
{
    char s1[1000],s2[1000];
    printf("Enter a String: ");
    gets(s1);
    ReverseString(s1,s2);
    getch();
}
