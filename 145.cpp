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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> q;
        vector<int> r;
        vector<bool> flag;
        if (!root)
            return {};
        q.push(root);
        flag.push_back(0);
        while (!q.empty()) {
            TreeNode* t= q.top();
            if (flag[q.size()-1]) {
                r.push_back(t->val);
                flag.erase(flag.begin()+q.size()-1);
                q.pop();
            }
            else {
                flag[q.size()-1] = 1;
                if (t->right) {
                    q.push(t->right);
                    flag.push_back(0);
                }
                if (t->left) {
                    q.push(t->left);
                    flag.push_back(0);
                }
            }
        }
        return r;
    }
};
