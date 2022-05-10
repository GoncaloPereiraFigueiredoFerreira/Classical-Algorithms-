#include <stdio.h>
#include <stdlib.h>

int* shift(int u[], int n, int k){
    int * new = malloc(sizeof(int)*n);
    int i=0;
    for (; i<n;i++)
        new[(i+k)%n] = u[i];
    return new;
}

int main(){
    int *arr= malloc(sizeof(int)*5);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr=shift(arr,5,2);
    for (int i=0; i<5;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    arr = shift(arr, 5, 2);
    for (int i = 0; i < 5; i++)
        printf("%d\t", arr[i]);
    return 0;
}