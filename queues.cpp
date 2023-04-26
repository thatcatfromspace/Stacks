#include <iostream>
#define N 10

using namespace std;

int queue[N];
int front = -1, rear = -1; 

bool isEmpty(){
    return front == -1 && rear == -1;
}

bool isFull(){
    return rear == N - 1;
}

void enqueue(int x){
    if (isFull()){
        return;
    }
    else {
        front++;
        queue[++rear] = x;
    }
}

int dequeue(){
    int r = -1;
    if (isEmpty()){
        return r;
    }
    else {
        int r = queue[front++];
    }
    return r;
}

void display(){
    for (int i = front; i = rear; i++){
        cout << queue[i] << endl;
    }
}

int main(){
    enqueue(4);
    enqueue(5);
    enqueue(6);
    dequeue();
}