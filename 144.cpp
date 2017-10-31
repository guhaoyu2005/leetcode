/*
Date:2016-09-19
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
 #include <stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        TreeNode* t = root;
        stack<TreeNode*> s;
        while (!s.empty() || t!=NULL) {
            if (t) {
                r.push_back(t->val);
                s.push(t);
                t=t->left;
            }
            else {
                t=s.top();
                s.pop();
                t=t->right;
            }
        }
        return r;
    }
};
