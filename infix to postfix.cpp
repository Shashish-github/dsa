#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    if (op == '^') return 1;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    char c;
    for (i = 0; infix[i]; i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop();
            }
        }
        else {
            while (top != -1 && precedence(stack[top]) > precedence(c)) {
                postfix[j++] = pop();
            }

            if (!isRightAssociative(c)) {
                while (top != -1 && precedence(stack[top]) == precedence(c)) {
                    postfix[j++] = pop();
                }
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; 
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

