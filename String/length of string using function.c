#include<stdio.h>
#include<conio.h>
int main()
{
     char s1[10000];
     printf("Enter Any Word: ");
     gets(s1);
     int length;
     length = strlen(s1);
     printf("%d",length);
     getch();
}
