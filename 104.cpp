/*
Date: 2016-09-14
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL) return 1;
        else return 1+max(root->left?maxDepth(root->left):0, root->right?maxDepth(root->right):0);
    }
};
