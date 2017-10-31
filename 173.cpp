/*
Date: 2016-09-28
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* curr;

    BSTIterator(TreeNode *root) {
        while (!s.empty())
            s.pop();
        curr = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (!s.empty() || curr)
            return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        int r = curr->val;
        curr = curr->right;
        return r;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
