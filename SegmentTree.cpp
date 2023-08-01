#include<iostream>
using namespace std;

class Node {
    int data;
    int startInterval;
    int endInterval;
    Node* left;
    Node* right;

    public:

    Node(int begin, int end) {
        startInterval = begin;
        endInterval = end;
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    friend class SegmentTree;
};

class SegmentTree {
    Node* root = nullptr;

    // segment tree storing 'Sum'
    Node* constructTree(int arr[], int start, int end) {
        if(start == end) {
            // leaf
            Node* leaf = new Node(start, end);
            leaf->data = arr[start];
            return leaf;
        }

        Node* node = new Node(start, end);

        int mid = (start+end)/2;

        node->left = constructTree(arr, start, mid);
        node->right = constructTree(arr, mid+1, end);

        node->data = node->left->data + node->right->data;

        return node;
    }

    int query(Node* node, int qstart, int qend) {
        if(node->startInterval >= qstart && node->endInterval <= qend) {
            return node->data;
        }
        else if(node->startInterval > qend || node->endInterval < qstart) {
            return 0;
        }
        else {
            return query(node->left, qstart, qend) + query(node->right, qstart, qend);
        }
    }

    int update(Node* node, int index, int value) {
        if(index >= node->startInterval && index <= node->endInterval) {
            if(node->startInterval == node->endInterval) {
                node->data = value;
                return node->data;
            }
            else {
                node->data = update(node->left, index, value) + update(node->right, index, value);

                return node->data;
            }
        }
        else {
            return node->data;
        }
    }

    public:

    SegmentTree(int arr[], int length) {
        root = constructTree(arr, 0, length-1);
    }

    int query(int qstart, int qend) {
        return query(root, qstart, qend);
    }

    void update(int index, int value) {
        root->data = update(root, index, value);
    }
};

int main() {

    int arr[8] = {3, 6, 12, 5, 22, 1, 17, 30};
    int length = sizeof(arr)/sizeof(arr[0]);
    cout<<length<<endl;
    SegmentTree *tree = new SegmentTree(arr, length);

    cout<<"The sum is "<<tree->query(1, 6)<<endl;
    tree->update(2, 14);
    cout<<"The sum is "<<tree->query(1, 6)<<endl;

    return 0;
}