/*
Date: 2016-09-21
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
 #include <map>
 class Solution {
 private:
     map<TreeNode* , int> m;
 public:
     int robit(TreeNode* root, bool canRob) {
         if (!root)
             return 0;
         if (canRob) {
             map<TreeNode*, int>::iterator it = m.find(root);
             if (it!=m.end())
                return it->second;
         }
         int left0 = root->left?robit(root->left, 0):0;
         int right0 = root->right?robit(root->right, 0):0;
         int left1 = root->left?robit(root->left, 1):0;
         int right1 = root->right?robit(root->right, 1):0;
         int maxL = max(left1, left0);
         int maxR = max(right1, right0);
         int rr = canRob?(max(left0 + right0 + root->val, maxL+maxR))
                            :(maxL+maxR);
         if (canRob)
            m.insert(pair<TreeNode*, int>(root, rr));
         return rr;
     }

     int rob(TreeNode* root) {
         return max(robit(root, 1), robit(root, 0));
     }
 };
