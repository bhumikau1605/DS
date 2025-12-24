#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int);
void pop();
void display();

int stack[SIZE];
int top = -1;

int main() {
    int value, choice;
    printf("NAME: BHUMIKA U \n USN: 1BM24CS073 \n");
    while (1) {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nWrong selection!!! Try again!!!");
        }
    }

    return 0;
}

void push(int value) {
    if (top == SIZE - 1) {
        printf("\nStack is Full!!! Insertion is not possible!!!");
    } else {
        top++;
        stack[top] = value;
        printf("\nInsertion success!!!");
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack is Empty!!! Deletion is not possible!!!");
    } else {
        printf("\nDeleted : %d", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is Empty!!!");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void peek(){
    if(top >= 0){
        int ele = stack[top];
        printf("Peeked: %d\n", ele);
    }
    else
        printf("Stack is empty. Cannot peek.\n");
}
