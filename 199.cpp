/*
Date: 2016-09-28
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
    vector<int> rightSideView(TreeNode* root) {
        int gap;
        vector<TreeNode*> queue;
        int pGaps = 0;
        int pQueue = 0;
        vector<int> r;
        if (!root)
            return {};
        queue.push_back(root);
        gap = 0;
        while (pQueue < queue.size()) {
            TreeNode* t=queue[pQueue];
            if (t->left)
                queue.push_back(t->left);
            if (t->right)
                queue.push_back(t->right);
            if (pQueue==gap) {
                r.push_back(queue[pQueue]->val);
                gap=queue.size()-1;
            }
            pQueue++;
        }
        return r;
    }
};
