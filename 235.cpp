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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) {
            int rv = root->val;
            int pv = p->val;
            int qv = q->val;
            if ((pv<=rv && qv>=rv) || (qv<=rv && pv>=rv))
                return root;
            else {
                if (pv<=rv && qv<=rv)
                    return lowestCommonAncestor(root->left,p,q);
                else if (pv>=rv && qv>=rv)
                    return lowestCommonAncestor(root->right,p,q);
                return NULL;
            }
        }
        else
            return NULL;
    }
};
