// BST functions

#include <iostream>
#include <memory>
using namespace std;


class BST {
private:
    struct Node {
        int value;
        Node* l;
        Node* r;
        Node(int v) : value(v), l(nullptr), r(nullptr) {}
    };



public:
    Node* root = nullptr;
    void insert(Node*& node, int val) {
        if (node == nullptr) {
            node = new Node(val);
            return;
        }
        if (val == node->value) {
            // duplicate: ignore or could handle counts
            cout << "Value " << val << " already in tree. Ignored.\n";
            return;
        }
        if (val < node->value) insert(node->l, val);
        else insert(node->r, val);
    }
    
    void search_rec(Node* node, int val) const {
        if (!node) {
            cout << "Value " << val << " not found in the tree.\n";
            return;
        }
        if (val == node->value) {
            cout << "Value " << val << " found in the tree.\n";
            return;
        }
        if (val < node->value) search_rec(node->l, val);
        else search_rec(node->r, val);
    }
    
    void search_itr(int val) const {
        Node* current = root;
        while (current) {
            if (val == current->value) {
                cout << "Value " << val << " found in the tree.\n";
                return;
            }
            if (val < current->value) current = current->l;
            else current = current->r;
        }
        cout << "Value " << val << " not found in the tree.\n";
    }

    void max_el(Node* node) const {
        if (!node) {
            cout << "Tree is empty.\n";
            return;
        }
        while (node->r) {
            node = node->r;
        }
        cout << "Maximum element is: " << node->value << "\n";
    }

    void min_el(Node* node) const {
        if (!node) {
            cout << "Tree is empty.\n";
            return;
        }
        while (node->l) {
            node = node->l;
        }
        cout << "Minimum element is: " << node->value << "\n";
    }

    void inorder_succ(Node* node, int val) const {
        Node* current = node;
        Node* successor = nullptr;
        while (current) {
            if (val < current->value) {
                successor = current;
                current = current->l;
            } else if (val > current->value) {
                current = current->r;
            } else {
                break;
            }
        }
        if (!current) {
            cout << "Value " << val << " not found in the tree.\n";
            return;
        }
        if (current->r) {
            current = current->r;
            while (current->l) {
                current = current->l;
            }
            cout << "Inorder successor of " << val << " is: " << current->value << "\n";
        } else if (successor) {
            cout << "Inorder successor of " << val << " is: " << successor->value << "\n";
        } else {
            cout << "No inorder successor for " << val << "\n";
        }
    }

    void inorder_pred(Node* node, int val) const {
        Node* current = node;
        Node* predecessor = nullptr;
        while (current) {
            if (val > current->value) {
                predecessor = current;
                current = current->r;
            } else if (val < current->value) {
                current = current->l;
            } else {
                break;
            }
        }
        if (!current) {
            cout << "Value " << val << " not found in the tree.\n";
            return;
        }
        if (current->l) {
            current = current->l;
            while (current->r) {
                current = current->r;
            }
            cout << "Inorder predecessor of " << val << " is: " << current->value << "\n";
        } else if (predecessor) {
            cout << "Inorder predecessor of " << val << " is: " << predecessor->value << "\n";
        } else {
            cout << "No inorder predecessor for " << val << "\n";
        }
    }
};

int main(){
    
    BST t;
    cout<<"Enter elements to insert into the BST (type -1 to stop): \n";
    int val;
    
    while(true){
        cin>>val;
        if(val==-1) break;
        t.insert(t.root, val);
    }
    
    cout<<"Enter value to search (recursive): ";
    cin>>val;
    t.search_rec(t.root, val);
    
    cout<<"Enter value to search (iterative): ";
    cin>>val;
    t.search_itr(val);

    t.max_el(t.root);
    
    t.min_el(t.root);
    
    cout<<"Enter value to find inorder successor: ";
    cin>>val;
    t.inorder_succ(t.root, val);
    
    cout<<"Enter value to find inorder predecessor: ";
    cin>>val;
    t.inorder_pred(t.root, val);
        
    return 0;
}