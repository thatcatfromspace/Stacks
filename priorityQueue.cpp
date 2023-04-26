#include <iostream>

struct node{
    int value;
    int priority;
    node* next;
}; 

node* head = nullptr;

bool isEmpty(){
    return head == nullptr;
}

void enqueue(int value, int priority){
    node* temp = new node;
    temp->value = value;
    temp->priority = priority;
    if (isEmpty()){
        temp->next = nullptr;
        head = temp;
        std::cout << "Value queued.\n";
        return;
    }
    if (head->priority > priority){
        temp->next = head;
        head = temp;
        return;
    }

    node* ptr = head;
    while (ptr->next != nullptr && ptr->next->priority < priority){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    std::cout << "Value queued.\n";
}

int* peek(){
    node *ptr = head;
    int* returnNode;
    returnNode[0] = head->value;
    returnNode[1] = head->priority;
    return returnNode;
}

void dequeue(){
    node* ptr = head;
    head = head->next;
    delete ptr;
}

void display(){
    node* ptr = head;
    while (ptr != nullptr){
        std::cout << "Priority: " << ptr->priority << " Value: "  << ptr->value << std::endl;
        ptr = ptr->next;
    }
}


int main(){
    enqueue(1, 1);
    enqueue(2, 3);
    enqueue(4, 5);
    enqueue(3, 2);
    display();
    std::cout << peek()[0] << " " << peek()[1];
    return 0;
}