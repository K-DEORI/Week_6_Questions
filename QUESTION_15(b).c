#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}

void infixToPrefix(char *exp) {
    char result[MAX], *e, x;
    int j = 0;
    reverse(exp);
    e = exp;
    while (*e != '\0') {
        if (isalnum(*e))
            result[j++] = *e;
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                result[j++] = x;
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(*e))
                result[j++] = pop();
            push(*e);
        }
        e++;
    }
    while (top != -1)
        result[j++] = pop();
    result[j] = '\0';
    reverse(result);
    printf("Prefix: %s", result);
}

int main() {
    char exp[] = "a+b*c";
    infixToPrefix(exp);
    return 0;
}
