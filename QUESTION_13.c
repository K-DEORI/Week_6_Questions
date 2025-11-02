#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Current Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        stack[++top] = val;
        printf("Pushed %d\n", val);
    }
    display();
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped %d\n", stack[top--]);
    display();
}

int main() {
    push(10);
    push(20);
    pop();
    push(30);
    pop();
    return 0;
}
