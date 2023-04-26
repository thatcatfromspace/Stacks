#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int value;
    node* next;
};
node* head = nullptr;

void push(){
    int n;
    node *temp, *ptr;
    cout << "Enter number of values to be pushed: ";
    cin >> n;
    temp = (node*)malloc(sizeof(node));
    for (int i = 0; i < n; i++){
        cout << "Enter value to be pushed: ";
        cin >> temp->value;
        temp->next = nullptr;
        if (head == nullptr){
            head = temp;
        }
        else {
            ptr = head;
            while (ptr->next != nullptr){
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}

void pop(){
    node *ptr = head;
    if (head == nullptr) return;
    else {
        while (ptr->next->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = nullptr;
    }
}

void display(){
    node *ptr = head;
    while (ptr->next != nullptr){
        cout << ptr->value << endl;
        ptr = ptr->next;
    }
}

int main(){
    push();
    display();
    pop();
    cout << "Popping out last value" << endl;
    display();
    pop();
    cout << "Popping out last value" << endl;
    display();
    return 0;

}
