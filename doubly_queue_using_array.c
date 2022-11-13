#include "stdio.h"
#define max 5

int push_rear();
int push_front();
int pop_front();
int pop_rear();
int display();

struct queue{
    //FIFO
    int a[max];
    int front;
    int rear;
}Q;

int main(){
    Q.rear=-1; Q.front=-1;
    int i,j,opt,qch;
    printf("\n1.Input Restrictive\n2.Output Restrictive\n");
    scanf("%d",&qch);
    if(qch==1) {
        do {
            printf("\n1. Insert from Rear\n2. Delete from front\n3. Delete from end\n4. Display\n5. Exit\n");
            scanf("%d", &opt);
            switch (opt) {
                case 1:
                    push_rear();
                    break;
                case 2:
                    pop_front();
                    break;
                case 3:
                    pop_rear();
                    break;
                case 4:
                    display();
            }
        } while (opt != 5);
    }
    else{
        do {
            printf("\n1. Insert from rear\n2. Insert from front\n3. Delete from front \n4. Display\n5. Exit\n");
            scanf("%d", &opt);
            switch (opt) {
                case 1:
                    push_rear();
                    break;
                case 2:
                    push_front();
                    break;
                case 3:
                    pop_front();
                    break;
                case 4:
                    display();
                    break;
            }
        } while (opt != 5);
    }

    return 0;
}

int push_rear(){
    int item,len;
    if (Q.rear == max - 1) {
        printf("Overflowed");
    }
    else {
        if (Q.rear == -1) {
            Q.front = 0;
            Q.rear = 0;
        } else {
            Q.rear++;
        }
        printf("Enter item to insert: ");
        scanf("%d",&item);
        Q.a[Q.rear]=item;
    }
    return 0;
}

int push_front(){
    int item,len;
    if ((Q.rear == max - 1 && Q.front==0) || (Q.front-Q.rear==1)) {
        printf("Overflowed");
    }
    else {
        if (Q.rear == -1) {
            Q.front = 0;
            Q.rear = 0;
        }
        else if(Q.front==0) {
            Q.front=max-1;
        }
        else{
            printf("\nhi\n");
            Q.front--;
        }
        printf("Enter item to insert: ");
        scanf("%d",&item);
        Q.a[Q.front]=item;
    }
    return 0;
}

int pop_front(){
    if(Q.rear==-1)
        printf("Underflowed");
    else{
        printf("%d Deleted", Q.a[Q.front]);
        if(Q.rear==Q.front){
            Q.rear=-1;
            Q.front=-1;
        }
        else
            Q.front++;
    }
}
int pop_rear(){
    if(Q.rear==-1)
        printf("Underflowed");
    else{
        printf("%d Deleted", Q.a[Q.rear]);
        if(Q.rear==Q.front){
            Q.rear=-1;
            Q.front=-1;
        }
        else
            Q.rear--;
    }
}

int display(){
    if(Q.rear==-1)
        printf("Underflowed");
    else if(Q.front<=Q.rear) {
        for (int i = Q.front; i <= Q.rear; i++)
            printf("%d\t", Q.a[i]);
    }
    else{
        for (int i = Q.front; i < max; i++)
            printf("%d\t", Q.a[i]);
        for (int i = 0; i <= Q.rear; i++)
            printf("%d\t", Q.a[i]);
    }
}
