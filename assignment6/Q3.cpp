// program to find the size of list (doubly linked list or circular linked list)

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

void size_DLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    cout<<"Size of Doubly Linked List: "<<count<<endl;
}

void size_CLL(Node* head){
    if(head == nullptr){
        cout<<"Size of Circular Linked List: 0"<<endl;
        return;
    }
    int count = 1;
    Node* temp = head->next;
    while(temp != head){
        count++;
        temp = temp->next;
    }
    cout<<"Size of Circular Linked List: "<<count<<endl;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    cout<<"choose the type of linked list:\n1. Doubly linked list\n2. Circular linked list\n";
    int choice;
    cin>>choice;
    if(choice == 1){
        while(true){
            cout<<"Enter data (-1 to stop): ";
            int data;
            cin>>data;
            if(data == -1) break;

            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;
            newNode->prev = tail;

            if(tail) tail->next = newNode;
            tail = newNode;
            if(!head) head = newNode;
        }
        
        size_DLL(head);
    }

    else if(choice == 2){
        while(true){
            cout<<"Enter data (-1 to stop): ";
            int data;
            cin>>data;
            if(data == -1) break;

            Node* newNode = new Node();
            newNode->data = data;

            if(!head){
                head = newNode;
                newNode->next = head;
            } else {
                tail->next = newNode;
                newNode->next = head;
            }
            tail = newNode;
        }
        
        size_CLL(head);
    }

    else{
        cout<<"Invalid choice!"<<endl;
    }
    
    return 0;
}