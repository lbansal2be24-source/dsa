// Menu driven program to perform operations on doubly linked list and circular linked list

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;    
};

void ins_DLL(Node*& head,Node*& tail){
    Node* newnode = new Node();
    if (head == nullptr){
        cout<<"List is empty. Inserting the first node."<<endl;
        cout<<"Enter data for the new node: ";
        cin>>newnode->data;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        head = newnode;
        tail = newnode;
        return;
    }

    else{
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
                newnode->next = head;
                newnode->prev = nullptr;
                head->prev = newnode;
                head = newnode;
                break;

            case 2:
                {
                    Node* temp = head;
                    while(temp->next != nullptr){
                        temp = temp->next;
                    }
                    cout<<"Enter data for the new node: ";
                    cin>>newnode->data;
                    temp->next = newnode;
                    newnode->prev = temp;
                    newnode->next = nullptr;
                    tail = newnode;
                }
                break;

            case 3:
                {
                    int val;
                    cout<<"Enter the value after which to insert: ";
                    cin>>val;
                    Node* temp = head;
                    while(temp != nullptr && temp->data != val){
                        temp = temp->next;
                    }
                    if(temp != nullptr){
                        cout<<"Enter data for the new node: ";
                        cin>>newnode->data;
                        newnode->next = temp->next;
                        newnode->prev = temp;
                        if(temp->next != nullptr){
                            temp->next->prev = newnode;
                        }
                        temp->next = newnode;
                    }
                    else {
                        cout<<"Node with value "<<val<<" not found."<<endl;
                    }
                }
                break;

            default:
                cout<<"Invalid choice."<<endl;
        }
    }
}


void ins_CLL(Node*& head,Node*& tail){
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

void del_DLL(Node*& head){
    if (head == nullptr){
        cout<<"List is empty. Nothing to delete."<<endl;
        return;
    }

    else{
        int val;
        cout<<"Enter value to delete: ";
        cin>>val;
        Node* temp = head;
    
        while(temp != nullptr){
            if(temp->data == val){
                if(temp->prev != nullptr){
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if(temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
                delete temp;
                cout<<"Node with value "<<val<<" deleted."<<endl;
                return;
            }
            temp = temp->next;
        }
    }
}

void del_CLL(Node*& head){
    if(head == nullptr){
        cout<<"List is empty. Nothing to delete."<<endl;
        return;
    }
    
    int val;
    cout<<"Enter value to delete: ";
    cin>>val;
    Node* temp = head;
    Node* toDel = nullptr;
    do {
        if(temp->data == val){
            toDel = temp;
            break;
        }
        temp = temp->next;
    } while(temp != head);

    if(toDel != nullptr){
        if(toDel->next == toDel){ // Only one node
            head = nullptr;
        } else {
            toDel->prev->next = toDel->next;
            toDel->next->prev = toDel->prev;
            if(toDel == head){
                head = toDel->next;
            }
        }
        delete toDel;
        cout<<"Node with value "<<val<<" deleted."<<endl;
    } else {
        cout<<"Node with value "<<val<<" not found."<<endl;
    }
}

void search_DLL(Node* head){
    int val;
    cout<<"Enter value to search: ";
    cin>>val;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val){
            cout<<"Node with value "<<val<<" is present in the list."<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"Node with value "<<val<<" not found."<<endl;
}

void search_CLL(Node* head){
    if(head == nullptr){
        cout<<"List is empty."<<endl;
        return;
    }
    int val;
    cout<<"Enter value to search: ";
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
        cout<<"Node with value "<<val<<" is present in the list.."<<endl;
    } else {
        cout<<"Node with value "<<val<<" not found."<<endl;
    }
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Choose the type of linked list to work with:"<<endl;
    cout << "1. Doubly Linked List"<<endl;
    cout << "2. Circular Linked List"<<endl;
    int choice;
    cin >> choice;

    if(choice == 1){
        cout << "Doubly Linked List selected." << endl;
        cout<<"Choose from the following options: "<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        int dll_choice;
        cin>>dll_choice;
        while (dll_choice != 4){
            switch(dll_choice){
                case 1:
                    ins_DLL(head , tail);
                    break;
                case 2:
                    del_CLL(head);
                    break;
                case 3:
                    search_CLL(head);
                    break;
                default:
                    cout<<"Invalid choice."<<endl;
            }
            cout<<"Choose from the following options: "<<endl;
            cout<<"1. Insertion"<<endl;
            cout<<"2. Deletion"<<endl;
            cout<<"3. Search"<<endl;
            cout<<"4. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>dll_choice;
        }
    }
    else if(choice == 2){
        cout << "Circular Linked List selected." << endl;
        cout<<"Choose from the following options: "<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        int cll_choice;
        cin>>cll_choice;
        while (cll_choice != 4){
            switch(cll_choice){
                case 1:
                    ins_CLL(head , tail);
                    break;
                case 2:
                    del_CLL(head);
                    break;
                case 3:
                    search_CLL(head);
                    break;
                default:
                    cout<<"Invalid choice."<<endl;
            }
            cout<<"Choose from the following options: "<<endl;
            cout<<"1. Insertion"<<endl;
            cout<<"2. Deletion"<<endl;
            cout<<"3. Search"<<endl;
            cout<<"4. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>cll_choice;
        }
    }
    else{
        cout << "Invalid choice." << endl;
    }

    return 0;
}