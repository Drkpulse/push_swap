#include <stdio.h>
#include <stdlib.h>

typedef struct Node_Stack{
    int number;
    struct Node_Stack* next;
    struct Node_Stack* previous;
} Node_Stack;

int main(int argc, char** argv[])
{
    Node_Stack first;

    first.number= 42;
    first.next= malloc(sizeof(Node_Stack));
    first.previous= NULL;

    first.next->number = 24;
    first.next->next = NULL;
    first.next->previous = NULL;

    printf("First Node Value - %d \nSecond Value - %d \n", first.number, first.next->number);

    Node_Stack* curr = &first;

    while (curr != NULL)
    {
        printf("%d\n", curr->number);
        curr = curr->next;
    }
    
}   