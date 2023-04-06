#include <iostream>

using namespace std;

int top = -1;
int Stack[32];

int IsEmpty(){
    if (top == -1) return 1;
    else return 0;
}

int isFull(){
    if (top == 9) return 1;
    else return 0;
}

void push(int n){
    if (isFull()){
        std::cout << "Stack is full. \n";
        return;
    }
    stackz[++top] = n;
}

void pop(){
    if (IsEmpty()){
        std::cout << "Nothing to pop. \n";
        return;
    }
    top--;
}
