#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

void pal(){
    
    cout<<"Enter characters to check for palindrome: ";
    string str;
    cin>>str;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for(char ch : str){
        Node* newNode = new Node();
        newNode->data = ch;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    Node* left = head;
    Node* right = tail;
    bool isPalindrome = true;
    
    while(left != nullptr && right != nullptr && left != right && left->prev != right){
        if(left->data != right->data){
            isPalindrome = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }
    
    if(isPalindrome){
        cout<<"The string is a palindrome."<<endl;
    } else {
        cout<<"The string is not a palindrome."<<endl;
    }
    }

int main(){
    pal();
    return 0;
}