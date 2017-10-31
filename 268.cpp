/*
Date: 2016-09-19
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for (auto i: nums)
            sum+=i;
        int tSum = (0+nums.size())*((nums.size()+1))/2;
        return tSum-sum;
    }
};
