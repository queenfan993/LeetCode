typedef struct dp {
    int max;
    int nextMax;
}dp;

int max(int a, int b)
{
    return a > b ? a : b;
}

dp getmax(struct TreeNode *root) {
    dp dt = {0, 0};
    if (!root) {
        return dt;
    }
    dp left = getmax(root->left);
    dp right = getmax(root->right);

    dt.max = max(root->val + left.nextMax + right.nextMax, left.max + right.max);
    dt.nextMax = left.max + right.max;
    return dt;
}

int rob(struct TreeNode* root) {
    dp dt = getmax(root);
    return max(dt.max, dt.nextMax);
}