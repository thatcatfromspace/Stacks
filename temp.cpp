#include <iostream>
#include <string>
#define SIZE 10
using namespace std;

int stack[SIZE];
int top = -1;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == SIZE - 1;
}

char pop(){
    if (isEmpty()){
        cout << "Stack underflow! \n";
        return '\0';
    }
    return stack[top--];
}

void push(char c ){
    if (isFull()){
        cout << "Stack overflow! \n";
        return;
    }
    stack[++top] = c;
}

char peek(){
    return stack[top];
}

bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }
    return false;
}

int precedence(char c){
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

bool isOperand(char c){
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        return true;
    }
    return false;
}

string infixToPostfix(string expression){
    string postfix = "";
    int size = expression.length();

    for (int i = 0; i < size; i++){
        char c = expression[i];
        
        if (isOperand(c)){
            postfix += c;
        }
        else if (isOperator(c)){
            while (!isEmpty() && precedence(c) <= precedence(peek()) && peek() != '('){
                postfix += pop();
            }
            push(c);
        }
        else if (c == '('){
            push(c);
        }
        else if (c == ')'){
            while (!isEmpty() && peek() != '('){
                postfix += pop();
            }
            pop();
        }
    }
    while (!isEmpty()){
        postfix += pop();
    }
    return postfix;
}

int main(){
    string expression;
    cout << "Enter expression: ";
    cin >> expression;
    cout << infixToPostfix(expression) << endl;
    return 0;
}
