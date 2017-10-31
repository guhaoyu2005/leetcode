/*
Date: 2016-09-20
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            int p1, p2;
            p1=i+1;
            p2=nums.size()-1;
            int currNum = nums[i];
            while (p1<=p2) {
                if (nums[p1]==currNum || nums[p2]==currNum)
                    return currNum;
                else {
                    p1++;
                    p2--;
                }
            }
        }
        return nums[0];
    }
};
/*
#include <map>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        int ans=0;
        for (auto i: nums) {
            if (m.find(i)==m.end()) {
                m.insert(pair<int, int>(i, 1));
            }
            else {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
*/
