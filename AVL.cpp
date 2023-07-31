#include<iostream>
using namespace std;

class AVL {

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

        friend class AVL;
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

        return rotate(node);
    }

    Node* rotate(Node* node) {

        if(height(node->left) - height(node->right) > 1) {
            // left's height is greater
            if(height(node->left->left) - height(node->left->right) > 0) {
                // left left
                return rightRotate(node);
            }
            if(height(node->left->left) - height(node->left->right) < 0) {
                // left right
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if(height(node->right) - height(node->left) > 0) {
            // right's height is greater
            if(height(node->right->left) - height(node->right->right) < 0) {
                // right right
                return leftRotate(node);
            }
            if(height(node->right->left) - height(node->right->right) > 0) {
                // right left
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    Node* leftRotate(Node* p) {

        Node* c = p->right;  // child
        Node* t = c->left;

        c->left = p;
        p->right = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return c;
    }

    Node* rightRotate(Node* p) {

        Node* c = p->left;  // child
        Node* t = c->right;

        c->right = p;
        p->left = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return c;
    }

    bool balanced(Node* node) {
        if(node == nullptr) {
            return true;
        }

        return ((abs(height(node->left) - height(node->right)) <= 1) && balanced(node->left) && balanced(node->right));
    }

    int height(Node* node) {
            if(node == nullptr) {
                return -1;
            }
            return node->height;
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

        AVL() {

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
    AVL *tree = new AVL();

    tree->insert(20);
    tree->insert(24);
    tree->insert(33);
    tree->insert(90);
    tree->insert(135);
    tree->insert(295);
    tree->insert(400);

    tree->inOrder();
    cout<<endl;

    cout<<tree->height()<<endl;

    if(tree->balanced()) {
        cout<<"The tree is balanced\n";
    }
    else {
        cout<<"The tree is unbalanced\n";
    }

    return 0;
}