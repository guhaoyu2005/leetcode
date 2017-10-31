/*
Date: 2016-09-15
*/
#include <map>
class Solution {
private:
    struct link {
        int val;
        int content;
        link* left;
        link* right;
    };
    link* root;
    vector<int> result;
    int count=0;
    int kk;
public:
    void indexTree(link* l) {
        if (count == kk)
            return;
        if (l) {
            indexTree(l->right);
            if (count == kk)
                return;
            result.push_back(l->content);
            count++;
            indexTree(l->left);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        kk=k;
        count = 0;
        std::map<int, int> m;
        for (auto i: nums) {
            std::map<int, int>::iterator it;
            it = m.find(i);
            if (it == m.end())
                m.insert(std::pair<int, int>(i, 1));
            else {
                it->second = it->second+1;
            }
        }
        std::map<int, int>::iterator it = m.begin();
        while (true) {
            if (it == m.end())
                break;
            link* t = new link();
            t->val = it->second;
            t->content = it->first;
            if (root) {
                link* curr= root;
                while (true) {
                    if (t->val > curr->val) {
                        if (curr->right)
                            curr=curr->right;
                        else {
                            curr->right = t;
                            break;
                        }
                    }
                    else if (t->val <= curr->val){
                        if (curr->left)
                            curr=curr->left;
                        else {
                            curr->left = t;
                            break;
                        }
                    }
                }
            }
            else {
                root = t;
            }

            it = std::next(it);
        }
        indexTree(root);
        return result;
    }
};
