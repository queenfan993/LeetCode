/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

int find_depth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_depth = find_depth(root->left);
        int right_depth = find_depth(root->right);
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }
}

int find_diameter(TreeNode* root){
    int temp=0;
    int left_depth = 0, right_depth = 0; 
    if (root == NULL){
        return 0;
    }
    if(root->left){
        left_depth = find_depth(root->left); // retrun the left subtree depth
    }
    if(root->right){
        right_depth = find_depth(root->right); // retrun the right subtree depth
    }
    int diameter = left_depth + right_depth;
    diameter = fmax(diameter, find_diameter(root->left));
    diameter = fmax(diameter, find_diameter(root->right));
    return diameter;
}


int diameterOfBinaryTree(struct TreeNode* root){
    return find_diameter(root);
}








