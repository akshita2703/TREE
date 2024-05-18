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
void preOrder(Node* root){
    if(!root) return ;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(Node* root){
    if(!root) return ;
   
    inOrder(root->left);
     cout<<root->data<<" ";
    inOrder(root->right);

}
void postOrder(Node* root){
    if(!root) return ;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}
// complexity of these 3 traversal are 
// O(n) time and O(h) space h is the height of node (incase of skewtree it will be O(n-- number of nodes))
int main(){

    Node* root = createTree();
    cout << root->data << endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;

    inOrder(root);

    return 0;

}