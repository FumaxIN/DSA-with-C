#include "stdio.h"

int main(){
    int arr[10],i,j,temp,n,k;
    printf("Enter number of elements you want to enter: ");
    scanf("%d", &n);
    /////////////////////// ARRAY INPUT ?//////////////////////
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    ////////////////   SORT ///////////////////
    for(i=0;i<n-1;i++){
        for(j=n-1;j>=i+1;j--){
            if(arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            /*
             //Uncomment to check each iteration:
            for(k=0;k<n;k++){
                printf("%d\t", arr[k]);
            }
            printf("\n");
             */
        }
    }
    for(k=0;k<n;k++){
        printf("%d\t", arr[k]);
    }
    return 0;

}
