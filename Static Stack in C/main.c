#include <stdio.h>

const int STACK_SIZE = 10;

typedef struct Stack Stack;

struct Stack {
    int top;
    int* elements;
    int size;
};


Stack new() {
    Stack stack;

    stack.top = -1;
    stack.size = STACK_SIZE;
    int elements[STACK_SIZE];
    stack.elements = elements;

    return stack;
}

int push(Stack* stack, int element) {
    if (stack->top +1 > stack->size) {
        return -1;
    }
    stack->elements[stack->top+1] = element;
    stack->top++;
    return 0;
}

int* pop(Stack* stack) {
    if (stack->top == -1) {
        return NULL;
    }
    int* element = &stack->elements[stack->top];
    stack->top--;
    return element;
}

int* get(Stack* stack, int index) {
    if (index < 0 || index > stack->top) {
        return NULL;
    }
    return &stack->elements[index];
}

int search(Stack* stack, int element) {
    int current_index = 0;
    while (current_index <= stack->top) {
        if (stack->elements[current_index] == element) {
            return current_index;
        }
        current_index ++;
    }
    return -1;
}

int main() {
    printf("Hello World\n");

    Stack stack = new();

    push(&stack, 123);
    push(&stack, 5);
    int* value_ptr = get(&stack, 0);
    if (!value_ptr) {
        printf("Invalid Index\n");
        return -1;
    }
    printf("%d\n", *value_ptr);

    int searched = search(&stack, 5);

    if (searched== -1) {
        printf("Not Found\n");
        return -1;
    }
    printf("Index of Searched Value = %d\n", searched);

    int* popped = pop(&stack);

    if(!popped) {
        printf("Couldn't Pop");
        return -1;
    }

    printf("%d\n", *popped);

    int searched_again = search(&stack, 5);

    if (searched_again== -1) {
        printf("Not Found\n");
        return -1;
    }
}