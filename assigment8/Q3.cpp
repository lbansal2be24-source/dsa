//BST 

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
            cout << "Value " << val << " already in tree. Ignored.\n";
            return;
        }
        if (val < node->value) insert(node->l, val);
        else insert(node->r, val);
    }
    void DelNode(Node*& node, int val) {
        if (node == nullptr) {
            cout << "Value " << val << " not found in tree.\n";
            return;
        }
        if (val < node->value) {
            DelNode(node->l, val);
        } 
        else if (val > node->value) {
            DelNode(node->r, val);
        }
        else {
            if (node->l == nullptr && node->r == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->l == nullptr) {
                Node* temp = node;
                node = node->r;
                delete temp;
            } else if (node->r == nullptr) {
                Node* temp = node;
                node = node->l;
                delete temp;
            } else {
                Node* successorParent = node;
                Node* successor = node->r;
                while (successor->l != nullptr) {
                    successorParent = successor;
                    successor = successor->l;
                }
                node->value = successor->value;
                if (successorParent->l == successor) {
                    DelNode(successorParent->l, successor->value);
                } else {
                    DelNode(successorParent->r, successor->value);
                }
            }
        }
    }
    void print(Node* node) {
        if (node == nullptr) return;
        print(node->l);
        cout << node->value << " ";
        print(node->r);
    }
    int getMaxDepth(Node* node) {
        if (node == nullptr) return 0;
        int leftDepth = getMaxDepth(node->l);
        int rightDepth = getMaxDepth(node->r);
        return max(leftDepth, rightDepth) + 1;
    }
    int getMinDepth(Node* node) {
        if (node == nullptr) return 0;
        int leftDepth = getMinDepth(node->l);
        int rightDepth = getMinDepth(node->r);
        return min(leftDepth, rightDepth) + 1;
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
    
    cout<<"Maximum Depth of BST: "<<t.getMaxDepth(t.root)<<"\n";
    cout<<"Minimum Depth of BST: "<<t.getMinDepth(t.root)<<"\n";
    
    cout<<"Enter element to delete from the BST: ";
    cin>>val;
    t.DelNode(t.root, val);
    
    cout<<"BST after deletion (Inorder Traversal): ";
    t.print(t.root);
    return 0;
}