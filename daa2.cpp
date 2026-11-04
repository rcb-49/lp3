#include <bits/stdc++.h>
using namespace std;

class Node {
public :
    char ch;
    int freq;
    Node *left,*right;

    Node(char c, int f){
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};
struct Comparator{
bool operator()(const Node *a,const Node *b){
    return a->freq > b->freq;
}};

void generateCodes(Node *root, string code,unordered_map<char,string> &huffmanCode){
    if(root==nullptr){
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        huffmanCode[root->ch] = code;
        return;
    }

    generateCodes(root->left,code + "0",huffmanCode);
    generateCodes(root->right,code+"1",huffmanCode);

} 

void huffmanEncoding(vector<char> &chars,vector<int> &freq){
    
    priority_queue<Node*,vector<Node*>,Comparator> pq;

    for(int i=0;i<chars.size();i++){
        pq.push(new Node(chars[i],freq[i]));
    }

    while(pq.size() > 1){
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top(); 
        pq.pop();

        Node *newNode = new Node('$',left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node *root = pq.top();

    unordered_map<char,string> huffmanCode;
    generateCodes(root,"",huffmanCode);

    cout<<"\nHuffman codes\n";

    for(auto &it:huffmanCode){
        cout<<it.first<<" : "<<it.second<<endl;
    }

}

int main(){

    vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F'};

    vector<int> freq = {5, 9, 12, 13, 16, 45};

    huffmanEncoding(chars,freq);

    return 0;
}
