/*
Date: 2016-09-19
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> s;
        vector<int> r;
        TreeNode* t = root;
        while (!s.empty() || t!=NULL) {
            if (t) {
                s.push(t);
                t=t->left;
            }
            else {
                t=s.top();
                r.push_back(t->val);
                s.pop();
                t=t->right;
            }
        }
        return r;
    }
};
