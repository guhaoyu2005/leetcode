/*
Date: 2016-09-27
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    struct TreeNode {
        Interval val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x, x), left(NULL), right(NULL){};
    };
    TreeNode* rootNode;
    /** Initialize your data structure here. */
    SummaryRanges() {
        rootNode = NULL;
    }

    void insert(TreeNode* root, int val) {
        if (!root) {
            return;
        }
        else {
            if (val>=(root->val).start && val<=(root->val).end)
                return;
            else if (val==(root->val).start-1) {
                if (root->left) {
                    TreeNode* max = root->left;
                    if (max->right) {
                        while (max->right->right) {
                            max = max->right;
                        }
                        if ((max->right->val).end == val-1) {
                            (root->val).start = (max->right->val).start;
                            TreeNode *tn = max->right;
                            max->right = tn->left;
                            delete tn;
                        }
                        else {
                            (root->val).start = val;
                        }
                    }
                    else {
                        if ((max->val).end==val-1) {
                            (root->val).start = (max->val).start;
                            root->left = max->left;
                            delete max;
                        }
                        else {
                            (root->val).start = val;
                        }
                    }
                }
                else
                    (root->val).start = val;
            }
            else if (val==(root->val).end+1) {
                if (root->right) {
                    TreeNode* min = root->right;
                    if (min->left) {
                        while (min->left->left) {
                            min = min->left;
                        }
                        if ((min->left->val).start == val+1) {
                            (root->val).end = (min->left->val).end;
                            TreeNode* tn = min->left;
                            min->left = tn->right;
                            delete tn;
                        }
                        else {
                            (root->val).end = val;
                        }
                    }
                    else {
                        if ((min->val).start==val+1) {
                            (root->val).end = (min->val).end;
                            root->right = min->right;
                            delete min;
                        }
                        else {
                            (root->val).end = val;
                        }
                    }
                }
                else
                    (root->val).end = val;
            }
            else {
                if (val<(root->val).start) {
                    if (root->left)
                        insert(root->left, val);
                    else
                        root->left = new TreeNode(val);
                }
                else if (val>(root->val).end) {
                    if (root->right)
                        insert(root->right, val);
                    else
                        root->right = new TreeNode(val);
                }
            }
        }
    }

    void addNum(int val) {
        if (rootNode)
            insert(rootNode, val);
        else {
            rootNode = new TreeNode(val);
        }
    }

    vector<Interval> traversal(TreeNode* root) {
        if (!root)
            return {};
        else {
            vector<Interval> r = traversal(root->left);
            r.push_back(root->val);
            vector<Interval> rr = traversal(root->right);
            for (auto i: rr)
                r.push_back(i);
            return r;
        }
    }

    vector<Interval> getIntervals() {
        return traversal(rootNode);
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
