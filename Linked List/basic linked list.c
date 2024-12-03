#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
     struct node *prev;
};
struct node newNode;

int main(){
    struct node *head = (struct node *) malloc(sizeof(struct node));
    struct node *first = (struct node *) malloc(sizeof(struct node ));
    struct node *sceond = (struct node *) malloc(sizeof(struct node ));
    struct node *third = (struct node *) malloc(sizeof(struct node ));
    struct node *fourth = (struct node *) malloc(sizeof(struct node ));

    head-> data = 5;
    first-> data = 6;
    sceond-> data = 9;
    third-> data = 3;
    fourth-> data = 4;

    head->next = first;
    first->next = sceond;
    sceond->next = third;
    third->next = fourth;
    fourth->next = NULL;

    while(head !=NULL){
        printf("%d ",head->data);
       head= head->next;
    }
    return 0;
}



