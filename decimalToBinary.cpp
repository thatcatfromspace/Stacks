#include <iostream>
#include <string>
#define SIZE 32

using namespace std;

int stack[SIZE];
int top = -1;

bool isFull(){
    return top == SIZE - 1;
}

bool isEmpty(){
    return top == -1;
}

void push(int n){
    if (isFull()){
        cout << "Stack underflow! \n";
        return;
    }  
    stack[++top] = n;
}

int pop(){
    if (isEmpty()){
        cout << "Stack overflow!\n";
        return -1;
    }
    return stack[top--];
}

void decimalToBinary(int number){
    int binary[32];
    int i = 0;
    while (number > 0){
        push(number % 2);
        number /= 2;
    }
    while (!isEmpty()){
        binary[i++] = pop();
    }   
    for (int j = 0; j < i; j++){
        cout << binary[j];
    }
}

int main(){
    int number;
    cout << "Enter number: ";
    cin >> number;
    decimalToBinary(number);
    return 0;
}