/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tree;

bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1 && !root2){
        return true;
    }
    if(!root1 || !root2){
        return false;
    }
    bool temp = true;
   
    //if((!sub1->left)&&(!sub1->right)&&(sub2->left||sub2->right)) return false;
    if(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)){
        temp = true;
    } else if (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)){
        temp = true;
    } else{
        temp = false;
    }
    return (temp && (root1->val==root2->val));
    //return leafCheck(root1, root2);
}





