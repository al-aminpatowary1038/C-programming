#include<stdio.h>
#define size 5
int q[size], f=-1,r=-1;

void enqe(){
    system("cls");
    int data;
    printf("Enter Data Foe Enqueue: ");
    scanf("%d",&data);
    if((r+1)%size == f){
        printf("Queue is Overflow\n");
    }
    else if(f==-1 && r ==-1){
        f =0;
        r=0;
        q[r]= data;
    }
    else{
        r = (r+1)%size;
        q[r]=data;
    }
}

void deque(){
    system("cls");
    if(f==-1 && r==-1){
        printf("Queue Is Underflow!\n");
    }
    else if(f==r){
        printf("The Dequeued Element is %d\n",q[f]);
        f=-1;
        r=-1;
    }
    else{
        printf("The Dequeued Element is %d\n",q[f]);
        f= (f+1)%size;
    }
}


void dis(){
    system("cls");
    if(f==-1 && r==-1){
        printf("Queue is Empty!!");
    }
    else if(r>=f){
            printf("Elements are: ");
        for(int i= f;i<=r;i++){
            printf("%d ",q[i]);
        }
    }
    else{
         printf("Elements are: ");
        for(int i=f; i<size-1;i++){
            printf("%d ",q[i]);
        }
        for(int i=0;i<=r;i++){
            printf("%d ",q[i]);
        }
    }
    printf("\n");
}


int main(){
    int a;
    printf("\t\t\t\tCircular Queue\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    while(1){
        printf("Enter Your Choice: ");
        scanf("%d",&a);

        switch(a){
        case 1:
            enqe();
            break;
        case 2:
            deque();
            break;
        case 3:
            dis();
            break;
        default:
            printf("Wrong Choice!!\n");
        }
    }
}
