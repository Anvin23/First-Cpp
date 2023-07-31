#include<iostream>
using namespace std;

class BST {

    class Node {

        int value;
        Node *left;
        Node *right;
        int height;

        public:

        Node(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
            height = 0;
        }

        friend class BST;
    };

    Node *root = nullptr;

    Node* insert(int val, Node* node) {
        if(node == nullptr) {
            node = new Node(val);
            return node;
        }

        if(val < node->value) {
            node->left = insert(val, node->left);
        }

        if(val > node->value) {
            node->right = insert(val, node->right);
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        return node;
    }

    int height(Node* node) {
            if(node == nullptr) {
                return -1;
            }
            return node->height;
        }

    bool balanced(Node* node) {
        if(node == nullptr) {
            return true;
        }

        return ((abs(height(node->left) - height(node->right)) <= 1) && balanced(node->left) && balanced(node->right));
    }

    void inOrder(Node* node) {
        if(node == nullptr) {
            return;
        }

        inOrder(node->left);
        cout<<node->value<<" ";
        inOrder(node->right);
    }

    public:

        BST() {

        }

        void inOrder() {
            inOrder(root);
        }

        void insert(int val) {
            root = insert(val, root);
        }

        int height() {
            return height(root);
        }

        bool isEmpty() {
            return root == nullptr;
        }

        bool balanced() {
            return balanced(root);
        }
};

int main() {
    BST *tree = new BST();

    tree->insert(20);
    tree->insert(14);
    tree->insert(33);
    tree->insert(90);
    tree->insert(2);

    tree->inOrder();
    cout<<endl;

    cout<<"The height of the tree is "<<tree->height()<<endl;

    if(tree->balanced()) {
        cout<<"The tree is balanced\n";
    }
    else {
        cout<<"The tree is unbalanced\n";
    }

    return 0;
}