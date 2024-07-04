#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>

using namespace std;

class HuffmanCoder {
    unordered_map<char, string> encoder;
    unordered_map<string, char> decoder;

    unordered_map<char, int> freq;


    class Node {
        public:
            char data;
            int freq;
            Node* left;
            Node* right;

            Node(char data, int freq) {
                this->data = data;
                this->freq = freq;
                left = right = NULL;
            }

            Node(char data, int freq, Node* left, Node* right) {
                this->data = data;
                this->freq = freq;
                this->left = left;
                this->right = right;
            }

            bool isLeaf() {
                return left == NULL && right == NULL;
            }

            friend class compare;
    };

    class compare {
        public:
            bool operator()(Node* l, Node* r) {
                return l->freq > r->freq;
            }
    };

    Node* root;

    void buildFreqMap(string text) {
        for(char c : text) {
            freq[c]++;
        }
    }

    void buildPriorityQueue(priority_queue<Node*, vector<Node*>, compare>& pq) {
        for(auto p : freq) {
            pq.push(new Node(p.first, p.second));
        }
    }

    void buildHuffmanTree(priority_queue<Node*, vector<Node*>, compare>& pq) {
        while(pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            int sum = left->freq + right->freq;
            pq.push(new Node('\0', sum, left, right));
        }
    }

    void buildCoders(Node* root, string str) {
        if(root == NULL) {
            return;
        }

        if(root->isLeaf()) {
            encoder[root->data] = str;
            decoder[str] = root->data;
        }

        buildCoders(root->left, str + "0");
        buildCoders(root->right, str + "1");
    }

    string encode(string text) {
        string encodedText = "";
        for(char c : text) {
            encodedText += encoder[c];
        }
        return encodedText;
    }

    string decode(string encodedText) {
        string decodedText = "";
        string str = "";
        for(char c : encodedText) {
            str += c;
            if(decoder.find(str) != decoder.end()) {
                decodedText += decoder[str];
                str = "";
            }
        }
        return decodedText;
    }

    public:
        HuffmanCoder(string text) {
            buildFreqMap(text);

            priority_queue<Node*, vector<Node*>, compare> pq;
            buildPriorityQueue(pq);

            buildHuffmanTree(pq);

            this->root = pq.top();
            buildCoders(root, "");
        }

        string encodeText(string text) {
            return encode(text);
        }

        string decodeText(string encodedText) {
            return decode(encodedText);
        }

        void displayCoders() {
            cout << "Encoder:" << endl;
            for(auto p : encoder) {
                cout << p.first << " : " << p.second << endl;
            }

            cout << "Decoder:" << endl;
            for(auto p : decoder) {
                cout << p.first << " : " << p.second << endl;
            }
        }

        void displayFreqMap() {
            cout << "Frequency Map:" << endl;
            for(auto p : freq) {
                cout << p.first << " : " << p.second << endl;
            }
        }

        int textSize(string text) {
            // 1 character is 1 byte
            return text.size();
        }

        float encodedTextSize(string encodedText) {
            // 1 bit per character in encoded text
            // no. of bytes = no. of bits / 8
            int size = encodedText.size(); 
            return (float)size/8;
        }
};



int main() {
    string text = "abbccda";
    HuffmanCoder coder(text);

    coder.displayFreqMap();
    coder.displayCoders();

    string encodedText = coder.encodeText(text);
    cout << "Encoded Text: " << encodedText << endl;

    string decodedText = coder.decodeText(encodedText);
    cout << "Decoded Text: " << decodedText << endl;

    cout<<"Size of text: "<<coder.textSize(text)<<" bytes"<<endl;
    cout << "Size of encoded text: " << coder.encodedTextSize(encodedText)<< " bytes"<<endl;

    return 0;
}
