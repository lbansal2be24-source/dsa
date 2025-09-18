// program to find the middle element of a singly linked list

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
Node* head = nullptr;
Node* tail = nullptr;
int size = 0;
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    ::size++;
    cout << "Inserted " << value << " at the beginning." << endl;
}
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    ::size++;
    cout << "Inserted " << value << " at the end." << endl;
}
void insertInBetween(int value, int position) {
    if (position < 1 || position > ::size + 1) {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    if (position == ::size + 1) {
        insertAtEnd(value);
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    ::size++;
    cout << "Inserted " << value << " at position " << position << "." << endl;
}

void middleElement() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element is: " << slow->data << endl;
}

int main(){
    int ch, val;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insertion in between\n";
        cout << "4. Find Middle Element\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                int position;
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertInBetween(val, position);
                break;
            case 4:
                middleElement();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 5);
    return 0;
}