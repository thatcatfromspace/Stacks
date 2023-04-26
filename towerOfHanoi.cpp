#include <iostream>
using namespace std;

struct Stack {
    int data[1000];
    int top;
};

void init(Stack& s) {
    s.top = -1;
}

void push(Stack& s, int x) {
    s.top++;
    s.data[s.top] = x;
}

int pop(Stack& s) {
    int x = s.data[s.top];
    s.top--;
    return x;
}

void towerOfHanoi(int n, Stack& source, Stack& dest, Stack& aux) {
    if (n == 1) {
        int x = pop(source);
        push(dest, x);
        cout << "Move disk " << x << " from rod " << (char)(source.top+'A') << " to rod " << (char)(dest.top+'A') << endl;
    } else {
        towerOfHanoi(n-1, source, aux, dest);
        
        int x = pop(source);
        push(dest, x);
        cout << "Move disk " << x << " from rod " << (char)(source.top+'A') << " to rod " << (char)(dest.top+'A') << endl;
        
        towerOfHanoi(n-1, aux, dest, source);
    }
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    Stack source, dest, aux;
    init(source);
    init(dest);
    init(aux);
    for (int i = n; i >= 1; i--) {
        push(source, i);
    }
    
    towerOfHanoi(n, source, dest, aux);
    
    return 0;
}
