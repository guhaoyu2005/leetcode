/*
Date: 2016-09-19
*/
#include <map>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            std::map<int, int> m;
            vector<int> result;
            for (auto i: nums1) {
                std::map<int, int>::iterator it = m.find(i);
                if (it== m.end())
                    m.insert(std::pair<int, int>(i, 1));
                else
                    it->second++;
            }
            for (auto i:nums2) {
                std::map<int, int>::iterator it = m.find(i);
                if (it!= m.end()) {
                    result.push_back(i);
                    it->second--;
                    if (it->second==0) {
                        m.erase(i);
                    }
                }
            }
            return result;
    }
};
