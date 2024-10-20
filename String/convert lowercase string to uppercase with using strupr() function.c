//Write a C program to convert lowercase string to uppercase.
#include<stdio.h>
#include<conio.h>
int main()
{
    char str[100000];
    printf("Enter a String in Lowercase Letter : ");
    gets(str);
    strupr(str);
    printf("String in Uppercase Letter: %s\n",str);
    getch();
}
