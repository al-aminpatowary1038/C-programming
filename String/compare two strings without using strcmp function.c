#include<stdio.h>
#include<conio.h>

 int StringCompare(char s1[],char s2[])
{
    int d=0,i=0;
    for(i=0; s1[i]!='\0'&& s2[i]!='\0';i++)
    {
        if(s1[i]!=s2[i])
        {
            d++;
            break;
        }

    }
    if(d==0 && s1[i]=='\0'&& s2[i]=='\0')
        return 1;
    else
        return 0;
}
int main()
{
    char s1[1111],s2[1111];
    printf("Enter first string: ");
    gets(s1);
    printf("Enter second string: ");
    gets(s2);
    if(StringCompare(s1,s2)==1){
        printf("Strings Are Same\n");}
        else{
        printf("Strings Are Not Same\n");}
    getch();
}
