/*
Date: 2016-09-20
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
    void indexTree(TreeNode* root) {
            if (ans.size()>=kk)
                return;
            if (root) {
                indexTree(root->left);
                ans.push_back(root->val);
                indexTree(root->right);
            }
    }

    int kthSmallest(TreeNode* root, int k) {
        kk = k;
        indexTree(root);
        return ans[k-1];
    }
private:
    vector<int> ans;
    int kk;
};
