// program to reverse a singly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;
Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(int data) {
    Node* temp = newNode(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;      
        curr = next;      
    }
    return prev; 
}
int main() {
    int n, data;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insert(data);
    }
    cout << "Original list: ";
    display();
    head = reverse(head);
    cout << "Reversed list: ";
    display();
    return 0;
}