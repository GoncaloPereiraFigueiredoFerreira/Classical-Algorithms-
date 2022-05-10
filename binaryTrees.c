#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int value;
    struct nodo *left, *right;
}Node,*Btree;

int addNodo(Btree *a, int value){
    if (*a){
        if ((*a)->value < value)
            return addNodo(&((*a)->right), value);
        else if ((*a)->value > value)
            return addNodo(&((*a)->left), value);
    }
    else {
        Btree temp = malloc(sizeof(struct nodo));   
        temp->value = value;
        temp->right = NULL;
        temp->left = NULL;
        *a = temp;
        return 0;
    }
}

int isHeap (Btree a){
    int flag, flagR, flagL;
    if (!a) return 1;
    else {
        if (a->right && a->left && (a->right)->value < a->value && a->left->value < a->value) {
            flag =0;
        }
        else if (a->right && (a->right)->value < a->value){
            flag = 0;
        }
        else if (a->left && a->left->value < a->value){
            flag = 0;
        }
        else flag=1;
       
        if (flag==0) return flag;

        flagR = isHeap(a->right);
        flagL = isHeap(a->left);
        if (flagR == 0 || flagL == 0) return 0;
        else return 1;
    }

}
Btree buildBST(int arr[], int n)
{
    int m = n / 2;
    Btree ret = malloc(sizeof(struct nodo));
    if (n == 0)
        return NULL;
    if (n == 1)
    {
        ret->value = *arr;
        ret->left = NULL;
        ret->right = NULL;
    }
    else
    {
        ret->value = arr[m];
        ret->left = buildBST(arr, n / 2);
        ret->right = buildBST(arr + n / 2 + 1, n - n / 2 - 1);
    }
    return ret;
}
void printTree(Btree a)
{ //para ja serve... (travessia pre-order)
    if (a)
    {

        printf("value: %d  \n", (a)->value);
        printTree((a)->left);
        printTree((a)->right);
    }
}
int main (){
    Btree a = NULL;
    /*printf(" Is heap: %d\n",isHeap(a));
    addNodo(&a,2);
    addNodo(&a, 30);
    printf(" Is heap: %d\n", isHeap(a));
    addNodo(&a, 40);
    printf(" Is heap: %d\n", isHeap(a));
    addNodo(&a,1);
    printf(" Is heap: %d\n", isHeap(a));*/
    int b[6]= {1,2,3,4,5,6};
    a = buildBST(b,6);
    printTree(a);

}