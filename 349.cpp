/*
Date: 2016-09-15
*/
#include <map>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> m, r;
        vector<int> result;
        for (auto i: nums1)
            if (m.find(i) == m.end())
                m.insert(pair<int, int>(i,i));
        for (auto i: nums2)
            if (m.find(i) != m.end() && r.find(i) == r.end())
                r.insert(pair<int, int>(i,i));
        for (auto i: r)
            result.push_back(i.first);
        return result;
    }
};
