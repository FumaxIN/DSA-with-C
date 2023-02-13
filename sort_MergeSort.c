#include "stdio.h"

int merge(int a[], int start, int mid, int end){
    int i,j,m,n;
    m = mid-start+1;
    n = end-mid;
    int l[m], r[n];

    //Filling L and R sub_arrays
    for(i=0;i<m;i++)
        l[i]=a[start+i];
    for(j=0;j<n;j++)
        r[j]=a[mid+1+j];

    i=0;
    j=0;
    int k = start;
    while(i<m && j<n){
        if(l[i]<=r[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=r[j];
            j++;
        }
        k++;
    }

    //copy leftover elements
    while(i<m){
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<n){
        a[k]=r[j];
        j++;
        k++;
    }
}


int MergeSort(int a[], int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        MergeSort(a, start, mid);
        MergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }
    return 0;
}

int main(){
    int arr[10],i,j,temp,loc,n,k,lb=0,mid;
    printf("Enter number of elements you want to enter: ");
    scanf("%d", &n);
    /////////////////////// ARRAY INPUT //////////////////////
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, n-1);

    for(i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}
