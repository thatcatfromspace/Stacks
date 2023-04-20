#include <iostream>

struct node{
    int value;
    int priority;
    node* next;
}; 

node* head = NULL;

bool isEmpty(){
    return head == NULL;
}

void enqueue(int value, int priority){
    node* temp = new node;
    temp->value = value;
    temp->priority = priority;
    if (isEmpty()){
        temp->next = NULL;
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
    while (ptr->next != NULL && ptr->next->priority < priority){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    std::cout << "Value queued.\n";
}

int peek(){
    node *ptr = head;
    int maxPriority = 0, index = 0, flag = 0;
    while (ptr->next != NULL){
        ptr = ptr->next;
        if (ptr->priority > maxPriority){
            maxPriority = ptr->priority;
            index++;
        }
        if (flag > index){
            index = flag;
        }
    }
    return index;
}

void dequeue(){
    node* ptr = head;
    head = head->next;
    delete ptr;
}

void display(){
    node* ptr = head;
    while (ptr != NULL){
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
    
    return 0;
}