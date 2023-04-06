#include <iostream>
#include <string>

using namespace std;

// Manually defined stack class
class Stack {
private:
    char* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top];
    }
};

// Function to check if a character is an operator
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

// Function to check if a character is an operand
bool isOperand(char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string expression) {
    int size = expression.length();
    Stack st(size);
    string postfix = "";

    for (int i = 0; i < size; i++) {
        char c = expression[i];

        if (isOperand(c)) {
            // If the character is an operand, append it to the postfix expression
            postfix += c;
        } else if (isOperator(c)) {
            // If the character is an operator
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek()) && st.peek() != '(') {
                // Pop operators from the stack and append them to the postfix expression
                postfix += st.pop();
            }
            // Push the current operator onto the stack
            st.push(c);
        } else if (c == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            st.push(c);
        } else if (c == ')') {
            // If the character is a closing parenthesis
            while (!st.isEmpty() && st.peek() != '(') {
                // Pop operators from the stack and append them to the postfix expression
                postfix += st.pop();
            }
            // Pop the opening parenthesis from the stack
            st.pop();
        }
    }

    // Pop any remaining operators from the stack and append them to the postfix expression
    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infixExpression = "a+b-c*(d/e)";
    cout << infixToPostfix(infixExpression);
}
