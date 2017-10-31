/*
Date: 2016-09-20
*/
#include <algorighm>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ele;
        for (auto i: matrix) {
            for (auto j: i) {
                ele.push_back(j);
            }
        }
        std::make_heap(ele.begin(), ele.end());
        std::sort_heap(ele.begin(), ele.end());
        return ele[k-1];
    }
};
