/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX(a, b) ((a)>(b))? (a):(b)

void find(struct TreeNode* root, int level, int* depth, int* column){
    if(!root) return;
    *depth = MAX(level, *depth);
    //printf("call: %d\n", root->val);
    column[level]++;
    
    find(root->left, level+1, depth, column);
    find(root->right, level+1, depth, column);
    return;
}

void traversal(struct TreeNode* root, int** tempSize, int level, int** result){
    if(!root) return;
    //printf("level, temp: %d, %d\n",level, (*tempSize)[level]);

    result[level][(*tempSize)[level]++] = root->val;

    //printf("result: %d\n", result[level][(*tempSize)[level]]);
    traversal(root->left, tempSize, level+1, result);
    traversal(root->right, tempSize, level+1, result);
    return;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = 0; //for the total level
    int column[2000] = {0}; // for the deepest level may be 2000

    find(root, 1, &depth, column); //find the three parameters above
    *returnColumnSizes = (int*)calloc(depth, sizeof(int));
    *returnSize = depth;
    
    int** result = (int**)malloc(sizeof(int*)*depth);
    
    //printf("depth: %d\n", depth);
    for(int i = 0; i < depth; i++){
        result[i] = (int*)calloc(column[i+1], sizeof(int));
    }
    traversal(root, returnColumnSizes, 0, result);

    return result;
}