/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool symmertricHelpler(struct TreeNode* left, struct TreeNode* right){
    if(!left && !right){
        return true;
    } else if((!left || !right)){
        return false;
    } // to prevent the null pointer
    
    if(left -> val == right -> val){
        return (symmertricHelpler(left->left, right->right) && symmertricHelpler(left->right, right->left));
    }

    return false;

}

bool isSymmetric(struct TreeNode* root){
    if(!root){
        return true;
    }
    else{
        return symmertricHelpler(root->left, root->right);
    }
    
}