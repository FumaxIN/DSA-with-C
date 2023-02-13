#include "stdio.h"

int main(){
    int arr[10],i,j,temp,loc,n,k;
    printf("Enter number of elements you want to enter: ");
    scanf("%d", &n);
    /////////////////////// ARRAY INPUT ?//////////////////////
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    for(i=0;i<n;i++){
        int min = i;
        for(j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min = j;
            }

        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

        for(k=0;k<n;k++){
            printf("%d\t", arr[k]);
        }
        printf("\n");
    }
}
