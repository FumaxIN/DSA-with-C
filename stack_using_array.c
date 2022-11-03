#include "stdio.h"
#define size 10
int show();
int push();
int pop();
int peak();
int isEmpty();
int isFull();
struct Stack{
    int stack[size], top;
} s;
int main(){
    int opt;
    s.top=-1;
//    int arr[10] = s.stack;
//    int top = s.top;
    do{
        printf("\nMain Menu:\n1. Push element in stack\n2. Pop element from stack\n3. Display peak element\n4. Display full stack\n5. Check for underflow\n6. Check for overflowed\n7. Exit\n");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                push();
                break;
            case 4:
                show();
                break;
            case 2:
                pop();
                break;
            case 3:
                peak();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
        }
    } while(opt!=7);

    return 0;
}

int push() {
    int number,tot;
    if (s.top == size-1)
        printf("Overflowed");
    else {
        printf("\nEnter number of elements you want to enter: "); scanf("%d",&tot);
        printf("\nEnter the elements:\n");
        for(int i=0;i<tot;i++){
            scanf("%d", &number);
            s.top++;
            s.stack[s.top] = number;
        }

        printf("Elements inserted\n");
    }
    return 0;
}

int pop(){
    if (s.top == -1)
        printf("Underflowed");
    else if(s.top!=-1){
        printf("%d popped",s.stack[s.top]);
        s.top--;
    }
    return 0;
}

int show(){
    if (s.top==-1)
        printf("Underflow");
    else if(s.top!=-1){
        for(int i=s.top;i>=0;i--){
            printf("%d\t",s.stack[i]);
        }
        printf("\n");
    }
    return 0;
}

int peak(){
    printf("%d is the peak element",s.stack[s.top]);
    return 0;
}

int isEmpty(){
    if(s.top==-1)
        printf("\nStack is empty");
    else
        printf("False\n");
    return 0;
}
int isFull(){
    if(s.top==size-1)
        printf("\nStack is Full");
    else
        printf("False\n");
    return 0;
}
