/**
 * Question 2
 * Chandrashekhar Tripathi    CSE/20/38
**/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// structure implementing stack
typedef struct stack
{
    int size;
    int top;
    int *arr;
}
stack;

// stack operations
int push(stack *ptr, int data);
int pop(stack *ptr);
bool isFull(stack *ptr);
bool isEmpty(stack *ptr);


int main(void)
{
    /******
     * Creating the stack (Part a of question 2)
    ******/
    stack *st = (stack *) malloc(sizeof(stack));
    st->size = 100;
    st->top = -1; // intitally
    st->arr = (int *) malloc(st->size * sizeof(int));

    printf("Stack has been created \n");
    
    /******
     * Insert 8 integers in the stack (Part b of question 2)
    ******/
    int no_elements = 8;
    printf("\nEnter 8 integer values to be pushed into Stack\n");
    int element;
    for (int i = 0; i < no_elements; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%i", &element);
        getchar();
        st->top = push(st, element);
    }
    
    /******
     * Displayig the stack (Part c of question 2)
    ******/
    printf("\nDisplaying the stack\n");
    if (!isEmpty(st))
    {
        for (int i = 0; i <= st->top; i++)
            printf("%i ", st->arr[i]);
        printf("\n");
    }

    /******
     * Delete the third element from the stack (Part d of question 2)
    ******/

    // array to store popped elements
    int popped_arr[st->top];

    // popping all the elements till third element
    int no_popped;
    for (int i = 0; no_elements - i > 3 && !isEmpty(st); i++)
    {
        popped_arr[i] = pop(st);
        no_popped = i;
    }

    // popping third element
    if (!isEmpty(st))
        printf("%d popped\n", pop(st));

    // pushing elements 
    for (int i = no_popped; i >= 0; i--)
    {
        st->top = push(st, popped_arr[i]);
    }

    /******
     * Print the remaining elements (Part d of question 2)
    ******/    
    if (!isEmpty(st))
    {
        for (int i = 0; i <= st->top; i++)
            printf("%i ", st->arr[i]);
        printf("\n");
    }

    // freeing the Dynamically allocated memory used for stack
    free(st->arr);
    free(st);

    return 0;
}


int push(stack *ptr, int data)
{
    if (ptr->top == ptr->size - 1)
        printf("Stack overflow no element can be inserted \n");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        printf(" %d is Pushed sucessfully \n", ptr->arr[ptr->top]);
    }
    return ptr->top;
}

int pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack underflow pop is not possible\n");
        return -1;
    }

    else
    {
        int val;
        val = ptr->arr[ptr->top];

        ptr->top--;
        return val;
    }
}

bool isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}