#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }

int main() {
    char exp[] = "-+2*31 9";  // Equivalent to (2 + (3*1)) - 9
    int n1, n2, n3;
    for (int i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        else if (exp[i] != ' ') {
            n1 = pop();
            n2 = pop();
            switch (exp[i]) {
                case '+': n3 = n1 + n2; break;
                case '-': n3 = n1 - n2; break;
                case '*': n3 = n1 * n2; break;
                case '/': n3 = n1 / n2; break;
            }
            push(n3);
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
