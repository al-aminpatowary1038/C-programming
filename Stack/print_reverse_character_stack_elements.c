#include<stdio.h>
#include<conio.h>
#define size 10000
char Stack [size];
int top= -1;

void push(char s2){
    if(top<size-1){
        top++;
        Stack[top] = s2;
    }
    else{
        printf("Overflow");
    }
}
void pop(){
    char temp ;
    temp = Stack[top];
    top--;
    printf("%c",temp);
}


int main(){
    char st[size];

    printf("Enter a String: ");
    gets(st);
    int i=0,len=0;
  while(st[i]!='\0'){
    len++;
    i++;
  }
  for( i=0;i<len;i++){
    push (st[i]);
  }
    
    for(i =0;i<len;i++){
       pop();
        }
    getch();
}
