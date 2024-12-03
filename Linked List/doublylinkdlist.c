#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node* createNode (int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data =data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};



int main(){
   struct node *head = createNode(1);
    struct node *first = createNode(3);
  struct  node *second = createNode(5);
   struct node *third = createNode(7);
   struct node *fourth = createNode(9);

    head -> next = first;
    first ->prev =  head;
    first ->next= second;
    second->prev= first ;
    second->next= third;
    third->prev= second;
    third->next= fourth;
    fourth->prev= third;
    fourth->next= NULL;

  struct  node *a = head;
    while(a){
        printf("%d ",a->data);
        a = a->next;
    }
    return 0;
}
