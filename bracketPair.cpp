#include <iostream>
#include <string>

int stackz[10];
int top = -1;

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
    //std::cout << stackz[top] << '\n';
    top--;
}

int main(){
    std::string pairs;
    std::cout << "Enter parenthesis: ";
    std::cin >> pairs;
    int length = pairs.length();
    for (int i = 0; i < length; i++){
        if (pairs[0] == ')'){
            std::cout << "Unbalanced. \n";
            return 0;
        }
        else if (pairs[i] == '('){
            push('(');
        }
        else if (pairs[i] == ')'){
            pop();
        }
    }
    if (top == -1) std::cout << "The bracket pairs are balanced. \n";
    else std::cout << "The bracket pairs are imbalanced. \n";
    return 0;
}
