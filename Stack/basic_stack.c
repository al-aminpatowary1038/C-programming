#include<stdio.h>
#include<conio.h>
#define size 5
int stack [size];
int top =-1;

void push(int x)
{
    if(top<size-1)
    {
        printf(" %d is pushed in the stack\n",x);
        top++;
        stack[top]=x;
    }
    else
    {
        printf("Stack is Overflow!\n");
    }

}
void pop()
{
    if(top>=0)
    {
        printf("One elements popped from stack\n");
        int temp= stack[top];
        top--;
    }
    else
    {
        printf("Stack is Underflow!\n");
    }
}

int main()
{
    printf("Current scenario of stack\n");
    push(100);
    push(10);
    push(52);
    pop();
    pop();
    pop();
    push(500);
    push(30);
    push(30);
    push(30);
    push(30);
    push(30);
    push(80);
    pop();
    pop();
    pop();
    push(50);
    push(70);
    push(30);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    getch();
}
