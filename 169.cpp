/*
Date: 2016-09-16
*/
#include <stdlib>
#include <math.h>
#include <map.h>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> m;
        for (auto i: nums) {
            std::map<int, int>::iterator it = m.find(i);
            if (it==m.end()) {
                m.insert(std::pair<int, int>(i, 1));
            }
            else {
                it->second++;
            }
        }
        int max=-1;
        int whoMax=0;
        for (auto i: m) {
            if (i.second>max) {
                max = i.second;
                whoMax= i.first;
            }
        }
        return whoMax;
    }
};
