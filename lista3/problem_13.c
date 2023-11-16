#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char c) {
    stack->data[++(stack->top)] = c;
}

char pop(Stack *stack) {
    return stack->data[(stack->top)--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
}

int isWellDefined(char expression[]) {
    Stack stack;
    initStack(&stack);

    int len = strlen(expression);

    for (int i = 0; i < len; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), expression[i])) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char expression[MAX_SIZE];
        scanf("%s", expression);

        if (isWellDefined(expression)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
