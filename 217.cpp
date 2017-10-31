/*
Date: 2016-09-16
*/
#include <map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> m;
        for (auto i: nums) {
            std::map<int, int>::iterator it = m.find(i);
            if (it!=m.end())
                return true;
            else {
                m.insert(std::pair<int, int>(i, 1));
            }
        }
        return false;
    }
};
