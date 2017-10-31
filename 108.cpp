/*
Date: 2016-09-22
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
    TreeNode* build(int st, int et, vector<int>& nums) {
        if (st>et)
            return NULL;
        int rt = nums[(st+et)/2];
        TreeNode* t = new TreeNode(rt);
        t->left = build(st, (st+et)/2-1, nums);
        t->right = build((st+et)/2+1, et, nums);
        return t;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0)
            return NULL;
        return build(0, nums.size()-1, nums);
    }
};
