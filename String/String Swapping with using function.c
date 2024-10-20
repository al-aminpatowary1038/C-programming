// String Swapping with using function
#include<stdio.h>
#include<conio.h>
int main()
{
    char st1[1000],st2[10000];
    printf("Enter First String: ");
    gets(st1);
      printf("Enter Second String: ");
    gets(st2);
    char temp[10000];
    strcpy(temp,st1);
     strcpy(st1,st2);
     strcpy(st2,temp);
     printf("\nAfter Swapping Strings Are:\n");
     printf("First String: %s\n",st1);
     printf("Second String: %s\n",st2);
     getch();
}
