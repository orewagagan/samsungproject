#include <stdio.h>
#include <stdlib.h>

#define MAX 2

struct Stack {
    int items[MAX];
    int top;
};




void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Element %d pushed to the stack.\n", value);
    }
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    } else {
        int poppedValue = s->items[s->top];
        s->top--;
        return poppedValue;
    }
}

int isPalindrome(struct Stack *s, int size) {
    int i;
    for (i = 0; i < size / 2; i++) {
        int poppedValue = pop(s);
        if (poppedValue == -1 || poppedValue != s->items[i]) {
            return 0; 
        }
    }
    return 1; 
}

void displayStack(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        int i;
        for (i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initStack(&stack);

    char choice;
    int value, size;

    do {
        printf("\nMenu:\n");
        printf("a. Push an element to Stack\n");
        printf("b. Pop an element from a Stack\n");
        printf("c. Demonstrate how Stack can be used to check Palindrome\n");
        printf("d. Demonstrate Overflow and Underflow situations on Stack\n");
        printf("e. Display the status of Stack\n");
        printf("f. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 'b':
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;

            case 'c':
                printf("Enter the size of the string: ");
                scanf("%d", &size);
                if (isPalindrome(&stack, size)) {
                    printf("The entered string is a palindrome.\n");
                } else {
                    printf("The entered string is not a palindrome.\n");
                }
                break;

            case 'd':
     
                break;

            case 'e':
                displayStack(&stack);
                break;

            case 'f':
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 'f');

    return 0;
}
