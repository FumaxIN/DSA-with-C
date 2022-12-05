#include "stdio.h"
#include "stdlib.h"

int push();
int pop();
int display();
//LIFO
struct node{
    int data;
    struct node *ptr;
};
struct node *head=NULL;

int main(){
    int i,j,opt;
    do{
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d",&opt);
        switch (opt) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    } while(opt!=4);
}

int push(){
    int item;
    struct node *newNode, *tempNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&item);
    newNode->data=item;
    if(head==NULL){
        head=newNode;
        newNode->ptr=NULL;
    }
    else{
        tempNode=head;
        while(tempNode->ptr!=NULL){
            tempNode=tempNode->ptr;
        }
        tempNode->ptr=newNode;
        newNode->ptr=NULL;

    }
    return 0;
}

int pop(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode,*sl_node;
        tempNode=head;
        head = tempNode->ptr;
        tempNode->ptr=NULL;
        free(tempNode);
        printf("First item deleted");
    }
    return 0;
}

int display(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode;
        tempNode=head;
        while(tempNode!=NULL){
            printf("%d\t",tempNode->data);
            tempNode=tempNode->ptr;
        }
    }

    return 0;
}
