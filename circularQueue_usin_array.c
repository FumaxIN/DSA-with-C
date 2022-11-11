#include "stdio.h"
#define max 5

int push();
int pop();
int display();

struct queue{
    //FIFO
    int a[max];
    int front;
    int rear;
}Q;

int main(){
    Q.rear=-1; Q.front=-1;
    int i,j,opt;
    do{
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d",&opt);
        switch(opt){
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
    }while(opt!=4);

    return 0;
}

int push(){
    int item,len;
    if (Q.rear == max - 1 && Q.front == 0) {
        printf("Overflowed");
    } else {
        if (Q.rear == -1) {
            Q.front = 0;
            Q.rear = 0;
        }
        else if (Q.rear == max - 1 && Q.front!=0){
            Q.rear=0;
            //Q.front--;
        }
        else {
            Q.rear++;
        }
        scanf("%d",&item);
        Q.a[Q.rear]=item;
    }
    return 0;
}

int pop(){
    if(Q.front==-1){
        printf("Underflowed");
    }
    else{
        printf("%d Deleted!",Q.a[Q.front]);
        if(Q.rear==Q.front){
            Q.rear=-1;
            Q.front=-1;
        }
        else{
            if(Q.front==max-1)
                Q.front=0;
            else
                Q.front++;
        }
    }

    return 0;
}

int display(){
    if(Q.front==-1){
        printf("Underflowed");
    }
    else{
        if(Q.front<=Q.rear){
            for(int i=Q.front;i<=Q.rear;i++){
                printf("%d\t",Q.a[i]);
            }
        }
        else{
            for(int i=Q.front;i<max;i++){
                printf("%d\t",Q.a[i]);
            }
            for(int i=0;i<=Q.rear;i++){
                printf("%d\t",Q.a[i]);
            }
        }
    }


    return 0;
}
