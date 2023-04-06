#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int value;
    node* next;
};
node* head = NULL;

void push(){
    int n;
    node *temp, *ptr;
    cout << "Enter number of values to be pushed: ";
    cin >> n;
    temp = (node*)malloc(sizeof(node));
    for (int i = 0; i < n; i++){
        cout << "Enter value to be pushed: ";
        cin >> temp->value;
        temp->next = NULL;
        if (head == NULL){
            head = temp;
        }
        else {
            ptr = head;
            while (ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}

void pop(){
    node *ptr = head;
    if (head == NULL) return;
    else {
        while (ptr->next->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = NULL;
    }
}

void display(){
    node *ptr = head;
    while (ptr->next != NULL){
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
