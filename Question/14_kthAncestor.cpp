//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* solve(Node *root, int &k, int node){
    if(!root)return NULL;
   
        if(root->data == node){
            return root;
    }
        
    Node* l =  solve(root->left,k,node);
    Node* r =  solve(root->right,k,node);
        
    if(l==NULL && r==NULL)return NULL;
    k--;
    if(k==0)return root;
    if(l)return l;
    return r;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
   if(!root&&root->data==node)return NULL;
   Node*ans = solve(root,k,node);
   return ans == NULL || k>0?-1:ans->data;
    
}


                            //    1  
                            //  2  
                            //    3
                            // 4     5
                            //         6

            // root ko check kiya null toh nhi h phir check kiya ki root ki value given node ki value k equal toh nhi h 
            // agr equal h toh node milgya return kra do node ko 
            // nhi toh left m dhundo 
            // nhi toh right m dunndo

            // agr left or right dono NULL h toh node mila nhi idhr null return krdo
            // agr dono m se kisi ki bhi value not null h toh k--;
            // but check krlo ki k ==0 toh nhi hogya h agr hogya h toh root return krdo
            // or jo not null h woh return krdo 
