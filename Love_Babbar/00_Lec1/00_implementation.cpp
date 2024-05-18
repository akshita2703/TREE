#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
   
};

// it return the node of the tree
Node* createTree(){
    cout<<"enter the value"<<endl;
    int data;
    cin>>data;

    //-1 means null 
    if(data == -1){
        return NULL;
    }
    // step1: create Node
    Node* root = new Node(data);
    // step2: create left subtree
    cout<<"left of node :"<<root->data<<endl;
    root-> left = createTree();
    //step3 : create right subtree
    cout<<"right of node :"<<root->data<<endl;

    root -> right = createTree();

    return root;
}

int main(){

    Node* root = createTree();
    cout << root->data << endl;

    return 0;

}