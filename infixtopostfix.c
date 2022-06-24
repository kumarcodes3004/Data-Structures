#include <stdio.h>
#include <ctype.h>
#define stack_size 50
#define length 50
int top = -1;
char s[50];

void push(char item)
{
    if (top == stack_size - 1)
    {

        printf(" overflow \n");
        return;
    }
    s[++(top)] = item;
}

char pop()
{
    char item_del;

    if (top == -1)
    {
        printf(" underflow \n ");
        return 0;
    }
    item_del = s[(top)--];
    return item_del;
}

int priority(char symbol)
{
    switch (symbol)
    {

    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 4;
    }
}

char infix[length], postfix[length];
void infix_to_postfix()
{

    char symbol;
    int i, j;
    top = -1;
    i = 0;
    push('#');
    j = 0;
    while ((symbol = infix[i++] )!= '\0')
    {

        if (symbol == '(')
            push(symbol);

        else if (isalnum(symbol))
            postfix[j++] = symbol;

        else if (symbol == ')')
        {
            while (s[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while (priority(s[top]) >= priority(symbol))
                postfix[j++] = pop();

            push(symbol);
        }
    }

    while (s[top] != '#')
        postfix[j++] = pop();

    postfix[j] = '\0';
}

void main()
{
    printf("enter valid infix expression ");
    scanf("%s", infix);

    infix_to_postfix();
    printf(" enter valid infix expression %s ", infix);
    printf("converted postfix expression %s", postfix);
}