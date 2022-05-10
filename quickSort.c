#include <stdio.h>
#include <stdlib.h>


void swap (int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
/* Wrong Solve
int partition(int *arr, int begin, int end){ //my res
    int pivot = end,i;
    for(i=0; i<end; i++){
        if ( (i < pivot && arr[i]> arr[pivot])|| (i > pivot && arr[i]< arr[pivot])){
            swap(arr+i,arr+pivot);
            pivot = i;
        }
    
    }
    return pivot;
}*/

int partition2 (int *arr, int begin, int end) 
{
    int pivot = arr[end];
    int i = begin-1;
    int j;
    for (j=begin ; j<end ; j++)
        if (arr[j] <= pivot) {
            i++;
            swap(arr+ i,arr+ j);
        }swap(arr+ i+1,arr+ end);
    return i+1;
}




void quickSort(int *arr, int p, int r){
    if (p<r){ 
        int i;
        int q = partition2 (arr,p,r);
        printf("\npivot's: %d\n",arr[q]);
        for(i=0;i<8;i++){
            printf("%d\t",arr[i]);}
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

int main (){
    int arr[8]={46,213,35,1,4,167,2,94};
    int N=8, i;
    printf("Unsorted elements:\n");
    for(i=0;i<N;i++){
        printf("%d\t",arr[i]);
    }

    quickSort(arr,0,N-1);
    printf("\n\nSorted elements:\n");
    for(i=0;i<N;i++){
        printf("%d\t",arr[i]);}
    
}