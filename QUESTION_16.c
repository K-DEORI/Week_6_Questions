#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }

int main() {
    char exp[] = "231*+9-";
    char *e = exp;
    int n1, n2, n3;

    while (*e != '\0') {
        if (isdigit(*e))
            push(*e - '0');
        else {
            n1 = pop();
            n2 = pop();
            switch (*e) {
                case '+': n3 = n2 + n1; break;
                case '-': n3 = n2 - n1; break;
                case '*': n3 = n2 * n1; break;
                case '/': n3 = n2 / n1; break;
            }
            push(n3);
        }
        e++;
    }
    printf("Result = %d\n", pop());
    return 0;
}
