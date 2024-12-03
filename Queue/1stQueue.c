#include<stdio.h>
#include<stdlib.h>
#define size 5
int que [size];
int front = -1 , rear = -1;


void enque(){
    int item;
    if(rear == size -1){
        printf("Queue is full\n");
    }
    else {
        if(front == -1 ){
            front = 0;
    }

    printf("Enter the element: ");
    scanf("%d",&item);
    rear++;
    que[rear] = item;
}
}

void deque(){

            if(front == -1 || front > rear){
                printf("Underflow\n");

            }
            else{
                printf("Deleted element is %d\n",que[front]);
                front++;
            }
}
void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue Elements are: ");
        for(int i=front;i<=rear;i++){
            printf("%d ",que[i]);
        }
        printf("\n");
    }
}


int main(){

        int a;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
       
        while(1){
             printf("Enter Your choice\n");
        scanf("%d",&a);
            switch(a){
                case 1: {
                    enque();
                break;
                }
                
                case 2: {
                     deque();
                break;
                }
               
                case 3:{
                     display();
                break;
                }
               
            }
        }
        getchar();
}
