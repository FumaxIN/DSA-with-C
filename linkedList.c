#include "stdio.h"
#include "stdlib.h"

int start_push();
int end_push();
int rand_push();
int start_del();
int end_del();
int rand_del();
int display();
int sum();
int search();
int reverse();
int sort();
int duplicate_remover();

struct node{
    int data;
    struct node *ptr;
};
struct node *head=NULL;







int main(){
    int i,j,opt;
    do{
        printf("\n1. Insert at start\n2. Insert at end\n3. Insert at desired position\n4. Delete from start\n5. Delete at end\n6. Delete at desired position\n7. Display\n8. Search\n9. Sum\n10. Reverse\n11. Sort\n12. Remove Duplicates\n13. Exit\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                start_push();
                break;
            case 2:
                end_push();
                break;
            case 3:
                rand_push();
                break;
            case 4:
                start_del();
                break;
            case 5:
                end_del();
                break;
            case 6:
                rand_del();
                break;
            case 7:
                display();
                break;
            case 8:
                search();
                break;
            case 9:
                sum();
                break;
            case 10:
                reverse();
                break;
            case 11:
                sort();
                break;
            case 12:
                duplicate_remover();
                break;
        }
    }while(opt!=13);

    return 0;
}



int start_push(){
    int item;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&item);
    newNode->data=item;
    newNode->ptr=head;
    head=newNode;
    printf("\nNew pointer is pointing to: %p",newNode->ptr);
    return 0;
}


int end_push(){
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


int rand_push(){
    int item,loc;
    struct node *newNode, *tempNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&item);
    newNode->data=item;
    printf("Enter location at which you want to insert: ");
    scanf("%d",&loc);
    tempNode=head;
    for(int i=0; i<loc-2; i++){
        printf("%d",i);
        tempNode=tempNode->ptr;
    }
    newNode->ptr = tempNode->ptr;
    tempNode->ptr=newNode;

    return 0;
}


int start_del(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *temp;
        temp = head;
        head = temp->ptr;
        free(temp);
    }
}


int end_del(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode,*sl_node;
        tempNode=head;
        while(tempNode->ptr!=NULL) {
            sl_node = tempNode;
            tempNode = tempNode->ptr;
        }
        sl_node->ptr=NULL;
        free(tempNode);
        printf("Last item deleted");
    }
}

int rand_del(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode, *sl_node;
        int loc;
        tempNode = head;
        printf("Enter location of the node to be deleted: ");
        scanf("%d",&loc);
        for(int i=0;i<loc-1;i++){
            sl_node = tempNode;
            tempNode=tempNode->ptr;
        }
        sl_node->ptr = tempNode->ptr;
        free(tempNode);
    }
    return 0;
}


int search(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode;
        int search_item,count=0;
        printf("Enter element you want to search for: ");
        scanf("%d",&search_item);
        tempNode=head;
        while(tempNode->ptr!=NULL){
            count++;
            if(tempNode->data==search_item){
                printf("Element found at %d",count);
                return 0;
            }

            tempNode=tempNode->ptr;
        }
    }
    return 0;
}

int sum(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode;
        int sum=0;
        tempNode=head;
        while(tempNode->ptr!=NULL){
            sum+=tempNode->data;
            tempNode=tempNode->ptr;
        }
        printf("Sum of values in Linked List = %d",sum+(tempNode->data));
    }
    return 0;
}

int reverse(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode,*temp1,*temp2,*sl_node;
        temp1=head;
        temp2=temp1->ptr;
        int count=1;
        tempNode=head;
        while(tempNode->ptr!=NULL){
            count++;
            sl_node = tempNode;
            tempNode = tempNode->ptr;
        }
        temp1->ptr=NULL;
//        printf("count = %d",count);
        head = tempNode;
        tempNode->ptr=sl_node;
        sl_node=temp1;
        temp1=temp2;
        int i=1;
        while(temp1!=tempNode){
            i++;
            struct node *address_temp = temp1->ptr;
            temp1->ptr=sl_node;
            sl_node=temp1;
            temp1 = address_temp;
        }
    }


    return 0;
}


int sort(){
    if(head==NULL){
        printf("Underflowed");
    }
    else{
        struct node *tempNode,*sl_node;
        int swapVar;
        for(sl_node=head;sl_node!=NULL;sl_node=sl_node->ptr){
            struct node *min = sl_node;
            for(tempNode=sl_node->ptr;tempNode!=NULL;tempNode=tempNode->ptr) {
                if (min->data > tempNode->data) {
                    min = tempNode;
                }
            }
                swapVar=sl_node->data;
                sl_node->data=min->data;
                min->data=swapVar;
        }
    }
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

int duplicate_remover(){
    struct node *tempNode, *tempNode2, *slNode, *delNode;
    int data,c=0;
    for(tempNode=head;tempNode->ptr!=NULL;tempNode=tempNode->ptr){
        data=tempNode->data;
        slNode=tempNode;
        tempNode2=tempNode->ptr;

        while(tempNode2 ->ptr!=NULL){
            c=0;
            if(tempNode2->data==data){
                slNode->ptr=tempNode2->ptr;
                delNode=tempNode2;
                c=1;
            }
            tempNode2=tempNode2->ptr;
            if(c==1) {
                free(delNode);
            }
            else
            slNode=slNode->ptr;
        }
    }
    return 0;
}
