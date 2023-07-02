/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tree;

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root) {
        return root;
    } else {
        root->left = invertTree(root -> left);
        root->right = invertTree(root -> right);
    }
    tree* temp = malloc(sizeof(tree));
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}