#include "stdio.h"

int QuickSort(int array[], int start, int end);
int partition(int array[], int start, int end);
int main(){
    int arr[20],i,j,n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    QuickSort(arr, 0, n-1);
    printf("\n");
    for(j=0;j<n;j++){
        printf("%d\t",arr[j]);
    }
    return 0;
}

int QuickSort(int array[], int start, int end){
    int p;
    if(start<end){
        p = partition(array, start, end);
        QuickSort(array, start, p - 1);
        QuickSort(array, p + 1, end);
    }
//    printf("%d",p);
}

int partition(int array[], int start, int end){
    int pivot,i, j,temp;
    pivot = array[start];
    i=start+1;
    j=end;
    do{
        while(array[i]<=pivot){
            i++;
        }
        while(array[j]>pivot){
            j--;
        }
        if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }while(i<j);

    temp=array[start];
    array[start]=array[j];
    array[j]=temp;
    return j;
}
