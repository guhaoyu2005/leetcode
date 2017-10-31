/*
Date: 2016-09-27
*/
class Solution {
public:
    int max(int a, int b) {
        return a>b?a:b;
    }
    int maxSubArray(vector<int>& nums) {
        int lastMax = -999999;
        int maxx = -999999;
        for (int i=0;i<nums.size();i++) {
            lastMax = max(nums[i], nums[i]+lastMax);
            if (lastMax>maxx)
                maxx = lastMax;
        }
        return maxx;
    }
};
