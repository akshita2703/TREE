void changeTree(BinaryTreeNode<int>*root){
    if(root == nullptr)return;
    int child =0;
    if(root->left){
        child+=root->left->val;
    }
    if(root->right){
        child+=root->right->val;
    }
    if(child>=root->val) root->data = child;
    else{
        if(root->left)root->left->data = root->data;
        else if(root->right)root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if(root->left) tot+=root->Left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data = tot;

}