#include <stdio.h>
#include <stdlib.h>


#define ESQ -1
#define BAL 0
#define DIR 1

typedef struct nodo {
    int bFactor;
    int value;
    struct nodo * right;
    struct nodo * left;

}*avlT;

typedef struct llint{
    int value;
    struct llint *next;
}*LInt;



void rotateLeft (avlT *a){
    avlT temp;
    temp = (*a)->right;
    (*a)->right = temp->left;
    temp->left = *a;
    *a = temp;
}

void rotateRight (avlT *a){
    avlT temp;
    temp= (*a)->left;
    (*a)->left = temp->right;
    temp->right = *a;
    *a = temp;
}

void correctRight(avlT *a){
    if ((*a)->right->bFactor == DIR ){ // rotaçao simples
        rotateLeft(a);
        (*a)->bFactor = BAL;
        (*a)->left->bFactor = BAL;
    }
    else { //double rotation
        rotateRight(&((*a)->right));
        rotateLeft(a);
        if ((*a)->bFactor == BAL){
            (*a)->left->bFactor = BAL;
            (*a)->right->bFactor = BAL;

        }
        else if ((*a)->bFactor == ESQ){
            (*a)->left->bFactor = BAL;
            (*a)->right->bFactor = DIR;
        }
        else {
            (*a)->left->bFactor =ESQ;
            (*a)->right->bFactor = BAL;
        }
        (*a)->bFactor = BAL;
    }
}
void correctLeft(avlT *a){
    if ((*a)->left->bFactor == ESQ ){ // rotaçao simples
        rotateRight(a);
        (*a)->bFactor = BAL;
        (*a)->right->bFactor = BAL;
    }
    else { //double rotation
        rotateLeft(&((*a)->left));
        rotateRight(a);
        if ((*a)->bFactor == BAL){
            (*a)->right->bFactor = BAL;
            (*a)->left->bFactor = BAL;

        }
        else if ((*a)->bFactor == DIR){
            (*a)->right->bFactor = BAL;
            (*a)->left->bFactor = ESQ;
        }
        else {
            (*a)->right->bFactor =DIR;
            (*a)->left->bFactor = BAL;
        }
        (*a)->bFactor = BAL;
    }
}




void insert (avlT *a , int value, int *cresceu){
    if ((*a) == NULL ){
        avlT temp = malloc(sizeof(struct nodo));
        temp->bFactor = BAL;
        temp->left = NULL;
        temp->right = NULL;
        temp->value = value;
        *a = temp;
        *cresceu =1;
    }
    else if (value < (*a)->value){
        insert(&((*a)->left), value, cresceu );
        if (*cresceu){
            if ( (*a)->bFactor == ESQ ){
                correctLeft(a);
                *cresceu=0;
            }
            else if ((*a)->bFactor == DIR){
                (*a)->bFactor =BAL;
                *cresceu=0;
            }
            else {
                (*a)->bFactor =ESQ;
                *cresceu=1;
            }
        }
    }
    else {
        insert(&((*a)->right), value, cresceu );
        if (*cresceu){
            if ( (*a)->bFactor == DIR ){
                correctRight(a);
                *cresceu=0;
            }
            else if ((*a)->bFactor == ESQ){
                (*a)->bFactor =BAL;
                *cresceu=0;
            }
            else {
                (*a)->bFactor =DIR;
                *cresceu=1;
            }
        }
    }
}



int alturaAVL(avlT a){
    int r, l;
    if (a == NULL) return 0;
    if (a->bFactor == BAL){
        r = alturaAVL(a->right);
        l = alturaAVL(a->left);
        if (r>l) return r+1; else return l+1;
    }
    else if (a->bFactor == DIR){
        r = alturaAVL(a->right);
        return r+1;
    }
    else return 1+ alturaAVL(a->left);

}

int deepest (avlT *a){
    int h,hr,hl;
    if (*a == NULL) h=0;
    else{
        if ((*a)->bFactor == DIR){
            h=deepest(&(*a)->right);
        }
        else if ((*a)->bFactor == ESQ){
                h = deepest(&(*a)->left);
            }
        else {
            hr = deepest(&(*a)->right);
            hl = deepest(&(*a)->left);
            if (hl>hr) h=hl+1;
            else h=hr+1;
        }
        return h;

    }
}

void printTree(avlT a)
{ //para ja serve... (travessia pre-order)
    if (a)
    {

        printf("value: %d bFactor :%d  \n", (a)->value, a->bFactor);
        printTree((a)->left);
        printTree((a)->right);
    }
}

avlT fromList (LInt l, int n){
    avlT tree=NULL, temp;
    while (l){
        if (tree == NULL){
            tree = malloc(sizeof(struct nodo));
            tree->bFactor = DIR;
            tree->left = NULL;
            tree->right = NULL;
            tree->value =l->value;

        }
        else{
            temp = tree;
            while (temp->right){
                if (temp->bFactor == BAL) {temp->bFactor = DIR; temp=temp->right;}
                else if (temp->bFactor == DIR) {rotateLeft(&temp);}
                
            }

            temp->right = malloc(sizeof(struct nodo));
            temp= temp->right;
            temp->value = l->value;
            temp->bFactor = BAL;
            temp->left = NULL;
            temp->right = NULL;
        }
        l=l->next;
        printTree(tree);
        printf("\n");
    }
    return tree;


}



LInt create (){
    LInt a = malloc(sizeof(struct llint));
    a->value = 1;
    a->next = malloc(sizeof(struct llint));
    a->next->value = 2;
    a->next->next = malloc(sizeof(struct llint));
    a->next->next->value = 3;
    a->next->next->next = malloc(sizeof(struct llint));
    a->next->next->next->value = 4;
    a->next->next->next->next = malloc(sizeof(struct llint));
    a->next->next->next->next->value = 5;
    a->next->next->next->next->next = malloc(sizeof(struct llint));
    a->next->next->next->next->next->value = 6;
    a->next->next->next->next->next->next = malloc(sizeof(struct llint));
    a->next->next->next->next->next->next->value = 7;
    a->next->next->next->next->next->next->next = NULL;
    return a;
}







void createTree(avlT *a){
    int *cresceu;
    *cresceu=0;
    insert(a,10,cresceu);
    printTree(*a);
    printf("\n");

    insert(a, 20, cresceu);
    printTree(*a);
    printf("\n");

    insert(a, 30, cresceu);
    printTree(*a);
    printf("\n");

    insert(a, 100, cresceu);
    printTree(*a);
    printf("\n");

    insert(a, 90, cresceu);
    printTree(*a);
    printf("\n");

    insert(a, 80, cresceu);
    printTree(*a);
    printf("\n");
}




int main (){
    avlT a = NULL;
    createTree(&a);
    //LInt l = create();
    //LInt temp;
    //for (temp = l; temp; temp=temp->next) printf("%d\t",temp->value);
    printf("\n");
    //a= fromList (l, 7);
    //int h = alturaAVL(a);
    printf("--> Final AVL tree\n");
    printTree(a);
    return 0;
}