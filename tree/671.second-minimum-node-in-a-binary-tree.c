/*
 * @lc app=leetcode id=671 lang=c
 *
 * [671] Second Minimum Node In a Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void helper(struct TreeNode* root, int* saver) {
    if (root == NULL) return;
    if (saver[0] == -1)
        saver[0] = root->val;
    else if (saver[1] == -1 && root->val != saver[0])
        saver[1] = root->val;
    else if (root->val < saver[0]) {
        saver[1] = saver[0];
        saver[0] = root->val;
    } else if (root->val > saver[0] && root->val < saver[1]) {
        saver[1] = root->val;
    }
    helper(root->left, saver);
    helper(root->right, saver);
}

int findSecondMinimumValue(struct TreeNode* root) {
    int saver[2] = {-1, -1};
    helper(root, saver);
    return saver[1];
}
