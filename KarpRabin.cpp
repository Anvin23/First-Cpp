#include<iostream>
#include<cmath>
using namespace std;

const int prime = 119;

double calculateHash(string str) {
    double hash = 0;
    for(int i = 0; i < str.length(); i++) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

double updateHash(double prevHash, char oldChar, char newChar, int patternLength) {
    double newHash = prevHash - oldChar;
    newHash /= prime;
    newHash += newChar * pow(prime, patternLength-1);
    return newHash;
}

void search(string text, string pattern) {
    int patternLength = pattern.length();
    double patternHash = calculateHash(pattern);
    double textHash = calculateHash(text.substr(0, patternLength));

    bool flag = false;

    for(int i=0;i<=text.length()-patternLength;i++) {
        if(patternHash == textHash && text.substr(i, patternLength) == pattern) {
            cout<<"Pattern found at index "<<i<<endl;
            flag = true;
        }
        if(i < text.length()-patternLength) { 
        textHash = updateHash(textHash, text[i], text[i+patternLength], patternLength);
        }
    }

    if(!flag) {
        cout<<"Pattern not found"<<endl;
    }
}

int main() {

    search("abvchnuewvk", "aa");
    search("abvchnuewvk", "hnu");

    return 0;
}