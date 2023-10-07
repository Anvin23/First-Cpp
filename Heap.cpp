#include<iostream>
#include<vector>
using namespace std;


// Min Heap
template<typename T>
class Heap {
    vector<T> v;

    void swap(int first, int second) {
    T temp = v[first];
    v[first] = v[second];
    v[second] = temp;
    }

    int parent(int index) {
        return (index-1)/2;
    }

    int leftChild(int index) {
        return 2*index + 1;
    }

    int rightChild(int index) {
        return 2*index + 2;
    }

    void upheap(int index) {
        if(index == 0) {
            return;
        }
        int parentIndex = parent(index);
        if(v[index] < v[parentIndex]) {
            swap(parentIndex, index);
            upheap(parentIndex);
        }
    }

    void downheap(int index) {
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);
        if(leftIndex >= v.size() && rightIndex >= v.size()) {
            return;
        }
        int minIndex = index;
        if(leftIndex < v.size() && v[leftIndex] < v[minIndex]) {
            minIndex = leftIndex;
        }
        if(rightIndex < v.size() && v[rightIndex] < v[minIndex]) {
            minIndex = rightIndex;
        }
        if(minIndex != index) {
            swap(minIndex, index);
            downheap(minIndex);
        }
    }

    public :
    
    void insert(T value) {
        v.push_back(value);
        upheap(v.size()-1);
    }

    T remove() throw() {
        if(v.size() == 0) {
            throw "Heap is empty";
        }
        T temp = v[0];
        v[0] = v[v.size()-1];
        v.pop_back();
        downheap(0);
        return temp;
    }

    vector<T> heapSort() {
        vector<T> sorted;
        while(v.size() != 0) {
            sorted.push_back(remove());
        }
        return sorted;
    }

};

int main() {
    Heap <int> heap1;

    heap1.insert(10);
    heap1.insert(50);
    heap1.insert(26);
    heap1.insert(3);
    heap1.insert(44);

    vector<int> sorted1 = heap1.heapSort();

    for(int i=0; i<sorted1.size(); i++) {
        cout<<sorted1[i]<<" ";
    }

    Heap<char> heap2;

    heap2.insert('f');
    heap2.insert('q');
    heap2.insert('n');
    heap2.insert('a');
    heap2.insert('l');

    cout<<heap2.remove()<<endl;

    vector<char> sorted2 = heap2.heapSort();

    for(int i=0; i<sorted2.size(); i++) {
        cout<<sorted2[i]<<" ";
    }

}