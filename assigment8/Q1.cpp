// Binary tree traversal : Inorder, Preorder, Postorder

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
    void inorder(Node* node) const {
        if (!node) return;
        inorder(node->l);
        cout << node->value << " -> ";
        inorder(node->r);
    }
    void preorder(Node* node) const {
        if (!node) return;
        cout << node->value << " -> ";
        preorder(node->l);
        preorder(node->r);
    }
    void postorder(Node* node) const {
        if (!node) return;
        postorder(node->l);
        postorder(node->r);
        cout << node->value << " -> ";
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
    
    cout<<"Inorder Traversal: ";
    t.inorder(t.root);
    cout<<"\nPreorder Traversal: ";
    t.preorder(t.root);
    cout<<"\nPostorder Traversal: ";
    t.postorder(t.root);
        
    return 0;
}