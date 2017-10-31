/*
Date: 2016-09-12

*/
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            std::map<int, int> a;
            int n=0;
            for (auto i: nums) {
                std::pair<int, int> atom = std::pair<int, int>(i, n);
                int chk = target-i;
                std::map<int, int>::iterator it = a.find(chk);
                if (!a.empty() && it != a.end()) {
                    result.push_back(it->second);
                    result.push_back(n);
                    break;
                    
                }
                a.insert(atom);
                n++;
            }
            return result;
    }
};
