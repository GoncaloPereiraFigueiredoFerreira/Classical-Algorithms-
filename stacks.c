#include <stdio.h>
#include <stdlib.h>


typedef struct stack{ //Stack as a struct
    int size;
    int filled;
    int *elem;
}*Stack;


int initStack (Stack *s){
    *s = malloc(sizeof(struct stack));
    (*s)->elem = malloc(sizeof(int));
    (*s)->size =1;
    (*s)->filled=0;
}

int push (Stack *s, int elem){
    if ((*s))
    {
        if ((*s)->size == (*s)->filled)
        {
            (*s)->size *= 2;
            (*s)->elem = realloc((*s)->elem, (*s)->size * sizeof(int));
        }
        (*s)->elem[(*s)->filled] = elem;
        (*s)->filled++;
    }
    else {
        return 1;
    }
    return 0;
}

int pop (Stack *s){
    if ((*s) && (*s)->filled > 0)
    {
        (*s)->filled--;
        return (*s)->elem[(*s)->filled];
    }
    else return -1;
}

int enqueue(Stack *s1, Stack *s2 ,int elem){
    return push(s1,elem);

}

int dequeue(Stack *s1, Stack *s2){
    if ((*s2)->filled == 0 && (*s1)->filled > 0)
    {
        while ((*s1)->filled != 0){
            push(s2,pop(s1));
        }
    }
    return pop(s2);
}

    int main()
{
    printf("//////////////////STACKS//////////////////\n");
    Stack s;
    printf("Init stack\n");
    initStack(&s);
    
    printf("Push : 15\n");
    push(&s,15);

    printf("Push : 23\n");
    push(&s, 23);

    printf("Pop: %d\n",pop(&s));

    printf("Push : 25\n");
    push(&s, 25);

    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));

    printf("\n//////////////////QUEUE//////////////////\n");
    Stack s1, s2;
    printf("Init stack S1\n");
    initStack(&s1);
    printf("Init stack S2\n");
    initStack(&s2);

    printf("Enqueue 20\n");
    enqueue(&s1, &s2, 20);
    printf("Enqueue 30\n");
    enqueue(&s1, &s2, 30);

    printf("Dequeue %d\n", dequeue(&s1, &s2));
    printf("Enqueue 40\n");
    enqueue(&s1, &s2, 40);
    printf("Dequeue %d\n", dequeue(&s1, &s2));
    printf("Dequeue %d\n", dequeue(&s1, &s2));
    printf("Dequeue %d\n", dequeue(&s1, &s2));
}   