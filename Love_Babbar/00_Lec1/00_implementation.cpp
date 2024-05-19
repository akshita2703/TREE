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
// space recursive stack space

int  levelOrder(Node* root){
    int count =1;
    if(!root) return 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL ){
            cout << endl;
            
            if(!q.empty()){
                count++;
                q.push(NULL);
            }
           
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);

        }
        
    }
    return count;
}

int maxDepth(Node * root){

    if(!root)return 0;
    int left = maxDepth(root->left);
    int right =maxDepth(root->right);
    return 1+max(left,right);
}

int searchIdx(int inorder[],int size, int element){
    for(int i =0;i<size;i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}

Node* constructTree(int preorder[], int &preIndx , int inorder[],int inStart,int inEnd,int size){
    // base case 
    if(preIndx>=size || inStart>inEnd) return NULL;
    // 1 case solve krte h
    int element = preorder[preIndx];
    preIndx++;
    Node* root = new Node(element);
    // element search krte h 
    int position = searchIdx(inorder,size,element);
    // bki case recursion smbhl lega
    root->left = constructTree(preorder,preIndx,inorder,inStart,position-1,size);
    root->right = constructTree(preorder,preIndx,inorder,position+1,inEnd,size);
    return root;
}


int main(){
    int inorder[] = {10,8,6,2,4,12};
    int preorder[] = {2,8,10,6,4,12};
    int preIndx = 0;
    int inStart = 0;
    int inEnd = 5;
    int size = 6;
    Node* root =  constructTree(preorder,preIndx,inorder,inStart,inEnd,size);
    cout<< "printing entire tree"<<endl;
    levelOrder(root);
//  2
// 8 8
// 10 10 10
// 6 6
// 4 4 4           ye glt output h kyuki mene preIndex by refernece nhi bhjaa
// 12 12 12 12

// 2          ye sahi output h boss
// 8 4
// 10 6 12
    

    // Node* root = createTree();
    // cout << root->data << endl;
    // preOrder(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // cout<<levelOrder(root);
    // cout<<endl;

    // cout<<maxDepth(root)<<endl;


   



    return 0;

}