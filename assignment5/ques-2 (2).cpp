//program to count the occurences of an element in singly linked list and delete all its occurences

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    int countOccurrences(int value)
    {
        int count = 0;
        Node *current = head;
        while (current != NULL)
        {
            if (current->data == value)
            {
                count++;
            }
            current = current->next;
        }
        return count;
    }
    void deleteOccurrences(int value)
    {
        while (head != NULL && head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        Node *current = head;
        Node *prev = NULL;
        while (current != NULL)
        {
            if (current->data == value)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
                size--;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        if (head == NULL)
        {
            tail = NULL;
        }
    }
    void display()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    int getSize()
    {
        return size;
    }
    ~LinkedList()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    int n, value, element;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insertAtEnd(value);
    }
    cout << "The linked list is: ";
    list.display();
    cout << "Enter the element to count and delete: ";
    cin >> element;
    int count = list.countOccurrences(element);
    cout << "The element " << element << " occurs " << count << " times in the linked list." << endl;
    list.deleteOccurrences(element);
    cout << "The linked list after deleting all occurrences of " << element << " is: ";
    list.display();
    return 0;
}