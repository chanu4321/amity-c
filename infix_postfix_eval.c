#include <stdio.h>
int precedence(char operator)
{
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


int main() {
    char infix[100]="a+b*(c^d-e)^(f+g*h)-i";
    int len=strlen(infix);
    char stack[100];
    int top=-1;
    char postfix[100];
    for(int i=0,j=0;i<len;i++){
        if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if (isOperator(infix[i])){
            while(top>-1 && )
            stack[++top]=infix[i];
        }
    }

    return 0;
}