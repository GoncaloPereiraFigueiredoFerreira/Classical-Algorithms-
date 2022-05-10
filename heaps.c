#include <stdio.h>
#include <stdlib.h>

#define PAI(i) (i-1)/2
#define FESQ(i) (2*i)+1
#define FDIR(i) 2*(i+1)
// #define HEIGHT(i) log2(i+1); 

typedef struct heap {
    int size; //Nº of max elements in heap
    int filled; //Nº of elements in heap
    int *elem;
}*Heap;

void swap (int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//max Heap
void bubbleUp (Heap *h){
    Heap l =*h;
    int lastId = l->filled -1;
    int flag=1;
    while(flag){
        if ( lastId != 0 && l->elem[PAI(lastId)]  < l->elem[lastId]){
            swap(&(l->elem[PAI(lastId)]),&(l->elem[lastId]) );
            lastId =PAI(lastId);
        }
        else flag=0;
    }
}

void bubbleDown (Heap *h){
    Heap l = *h;
    int id = 0;
    int flag=1;
    while (flag){
        if (FDIR(id) < l->filled ){ //garantir q tem filhos // se tiver filhos a direita tem a esquerda
            if (l->elem[FESQ(id)] >l->elem[FDIR(id)]){
                if (l->elem[id] < l->elem[FESQ(id)] ){
                    swap(&(l->elem[id]),&( l->elem[FESQ(id)]));
                    id = FESQ(id);}
                else flag=0;
            }
            else {
                if (l->elem[id] < l->elem[FDIR(id)] ){
                    swap(&(l->elem[id]),&( l->elem[FDIR(id)]));
                    id = FDIR(id);}
                else flag=0;
            }
        }
        else if (FESQ(id) < l->filled){
            if (l->elem[id] < l->elem[FESQ(id)] ){
                    swap(&(l->elem[id]),&( l->elem[FESQ(id)]));
                    id = FESQ(id);}
                else flag=0;
            }
        
        else flag=0;
    }
}
//Max heap
int insert (Heap *h, int value){
    Heap l;
    if ((*h)->filled == (*h)->size){
       (*h)->elem = realloc((*h)->elem, (*h)->size*2 * sizeof(int));
       if ((*h)->elem  == NULL) return 1;
       (*h)->size*=2;
       printf("Size doubled %d\n",(*h)->size);
    }
    l= *h;
    l->elem[l->filled] = value;
    l->filled++;
    bubbleUp(h);

    return 0;
}

int removeMax(Heap *h, int *value){
    if ((*h)->filled == 0) return 1;
    *value = (*h)->elem[0];
    (*h)->filled--;
    if ((*h)->filled > 0){
        swap(&((*h)->elem[0]), &((*h)->elem[(*h)->filled]));
        bubbleDown(h);}
    return 0;
}

void printHeap (Heap h){
    int i =0;
    printf("Heap Size: %d \n Positions Filled: %d\n Elements: ", h->size, h->filled );
    while (i< h->filled){
        printf ("%d\t", h->elem[i]);
        i++;
    }
}








int main (){
    Heap h = malloc (sizeof(struct heap));
    h->size = 2;
    h->filled=0;
    h->elem = malloc(sizeof(int) * h->size);
    int arr[10] = {43,12,56,98,23,65,54,26,49,30};
    int i=0, ret,j;
    int value[10];
    printf("\n/////////////////////Max heaps exercise/////////////////////////\n\n");
    printf("----Adding elements: \n");
    for (i=0; i < 10; i++){
        ret = insert(&h,arr[i]);
        if (ret == 0) {
            for (j=0;j< h->filled; j++){
                printf("%d\t", h->elem[j]);
            }
            printf("\n");}
        
    }
    printf("\n----Removing elements: \n");
    for (i=0; i<10; i++){
        for (j=0;j< h->filled; j++){
                printf("%d\t", h->elem[j]);
            }
            printf("\n");
    
        ret = removeMax(&h,&value[i]);
     }
    printf("----Greater elements: \n");
    for (i=0; i<10; i++){
        printf("%d\t", value[i]);
    }
    printf("\n\n///////////////////////////////END////////////////////////////\n\n");
    
}