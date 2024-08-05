#include <stdio.h>
#include <stdlib.h>

int top = -1;
int inp_array[4];
int SIZE = sizeof(inp_array) / sizeof(inp_array[0]);

void push();
void pop();
void show();
int isFull();
int isEmpty();
void full();
void empty();
void peek();

int main() {
    int choice;

    while (1) {
        printf("\nPerform operations on the stack:");
        printf("\n1. Push the element");
        printf("\n2. Pop the element");
        printf("\n3. Show");
        printf("\n4. Full");
        printf("\n5. Empty");
        printf("\n6. Peek");
        printf("\n7. End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            full();
            break;
        case 5:
            empty();
            break;
        case 6:
            peek();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push() {
    int x;

    if (isFull()) {
        printf("\nOverflow!!");
    } else {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nUnderflow!!");
    } else {
        printf("\nPopped element: %d", inp_array[top]);
        top = top - 1;
    }
}

void show() {
    if (isEmpty()) {
        printf("\nStack is empty!!");
    } else {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}

int isFull() {
    return top == SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void full() {
    if (isFull()) {
        printf("The stack is full");
    } else {
        printf("The stack is not full");
    }
}

void empty() {
    if (isEmpty()) {
        printf("The stack is empty.");
    } else {
        printf("The stack is not empty.");
    }
}

void peek() {
    if (isEmpty()) {
        printf("\nStack is empty!!");
    } else {
        printf("\nTop element is %d", inp_array[top]);
    }
}
