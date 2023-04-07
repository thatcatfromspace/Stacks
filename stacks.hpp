#include <iostream>
#define SIZE 32

namespace stacks{  // Basic stack operations
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
            std::cout << "Stack underflow! \n";
            return '\0';
        }
        return stack[top--];
    }

    void push(char c ){
        if (isFull()){
            std::cout << "Stack overflow! \n";
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
}