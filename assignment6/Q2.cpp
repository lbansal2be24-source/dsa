// circular linked list, display of all nodes with the first node repeating at last.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void print(Node* head){
    if(head == nullptr){
        cout<<"List is empty."<<endl;
        return;
    }
    Node* temp = head;
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while(temp != head);
    cout<<head->data;
}

void insert(Node*& head,Node*& tail){
    if (head == nullptr){
        cout<<"List is empty. Inserting the first node."<<endl;
        Node* newnode = new Node();
        cout<<"Enter data for the new node: ";
        cin>>newnode->data;
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        tail = newnode;
        return;
    }

    else{
        Node* newnode = new Node();
    
    cout<<"Choose insertion position: "<<endl;
    cout<<"1. At Beginning"<<endl;
    cout<<"2. At End"<<endl;
    cout<<"3. After a specific node"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"Enter data for the new node: ";
            cin>>newnode->data;
            if(head == nullptr){
                head = newnode;
                tail = newnode;
                newnode->next = newnode;
                newnode->prev = newnode;
            } else {
                newnode->next = head;
                newnode->prev = tail;
                head->prev = newnode;
                tail->next = newnode;
                head = newnode;
            }
            break;

        case 2:
            cout<<"Enter data for the new node: ";
            cin>>newnode->data;
            if(tail == nullptr){
                head = newnode;
                tail = newnode;
                newnode->next = newnode;
                newnode->prev = newnode;
            } else {
                newnode->next = head;
                newnode->prev = tail;
                tail->next = newnode;
                head->prev = newnode;
                tail = newnode;
            }
            break;

        case 3:
            {
                int val;
                cout<<"Enter the value after which to insert: ";
                cin>>val;
                Node* temp = head;
                bool found = false;
                do {
                    if(temp->data == val){
                        found = true;
                        break;
                    }
                    temp = temp->next;
                } while(temp != head);
                
                if(found){
                    cout<<"Enter data for the new node: ";
                    cin>>newnode->data;
                    newnode->next = temp->next;
                    newnode->prev = temp;
                    temp->next->prev = newnode;
                    temp->next = newnode;
                    if(temp == tail){
                        tail = newnode;
                    }
                } else {
                    cout<<"Node with value "<<val<<" not found."<<endl;
                }
            }
            break;

        default:
            cout<<"Invalid choice."<<endl;
        }
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    cout<<"enter number of nodes to create initially: ";
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        insert(head,tail);
    }

    cout<<"the circular linked list is: ";
    print(head);

    return 0;
}