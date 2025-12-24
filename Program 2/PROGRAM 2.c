#include <stdio.h>
#include <ctype.h>  // for isalnum()

// Assume stack, push, pop, pr, top declared elsewhere
#define SIZE 10
char stack[SIZE];
int top=-1;
push(char el){
    stack[++top]=el;
}
char pop(){
return (stack[top--]);
}
int pr(char sym){
if(sym=='^') return 3;
else if(sym=='*'||sym=='/') return 2;
else if(sym=='+'||sym=='-') return 1;
else return 0;

}
void main() {
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    printf("NAME: BHUMIKA U \nUSN: 1BM24CS073\n");
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('#');  // push sentinel to stack

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(') {
            push(ch);
        }
        else if (isalnum(ch)) {
            postfix[k++] = ch;   // append operand to postfix
        }
        else {
            if (ch == ')') {
                // pop until '(' is found
                while (stack[top] != '(')
                    postfix[k++] = pop();
                elem = pop();  // remove '('
            }
            else {
                // operator
                while (pr(stack[top]) >= pr(ch))
                    postfix[k++] = pop();
                push(ch);
            }
        }
    }

    // pop remaining operators till sentinel
    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';  // null terminate postfix string

    printf("\nPostfix Expression = %s\n", postfix);
}
