#include <stdlib.h>
#include <stdio.h>

#define HSIZE 10

typedef struct node{
    int key;
    int value;
    struct node *next;
}*Lock;

typedef Lock HashT[HSIZE];

int hash (int key){
    return key%HSIZE;
}

void store (HashT h, int key, int value){
    int id = hash(key);
    Lock temp = malloc(sizeof(struct node));
    Lock pt = h[id];
    temp -> key = key;
    temp -> value = value;
    temp -> next = NULL;

    if (pt !=NULL){
        while (pt->next && pt->key !=key ) pt = pt->next;
        if (pt == NULL) pt->next = temp;
        else pt->value = value;
        }
    else {
        h[id] = temp;
    }
}

int lookUp (HashT h, int key){
    int id = hash(key);
    Lock pt = h[id];
    while (pt && key != pt->key) pt = pt->next;
    if (pt==NULL) return -1;
    else return pt->value;
}

int quantos (int v[], int N) {
    HashT h;
    int i=0;
    for(;i<HSIZE; h[i++]=NULL);
    i=0;
    int id, counter=0;
    while (i<N){

        id = lookUp(h,v[i]);
        if (id == -1) {
            counter++;
            store(h,v[i],i);    
        }
        i++;
    } 
    return counter;
}





int main (){
    HashT h;
    int i=0;
    int arr[5] = {1,1,3,4,1};
    for(;i<HSIZE; i++) h[i]=NULL;
    store(h,23,40);
    store(h,3245,70);
    store(h,12353,10);
    store(h,2512,30);
    //int value = lookUp(h,243);
    //printf("Value : %d", value);
    printf("Counter : %d",quantos(arr,5));
    return 0;
}
