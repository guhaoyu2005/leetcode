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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //leaf
        if (!root)
            return NULL;
        TreeNode* r = root->right;
        root->right = invertTree(root->left);
        root->left  = invertTree(r);
        return root;
    }
};
