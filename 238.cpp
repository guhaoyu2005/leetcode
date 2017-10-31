/*
Date: 2016-09-15
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> numf,numb;
        numf.push_back(nums[0]);
        numb.push_back(nums[nums.size()-1]);
        for (int i=1;i<nums.size();i++) {
            numf.push_back(nums[i]*numf[i-1]);
            numb.push_back(nums[nums.size()-i-1]*numb[i-1]);
        }
        vector<int> r;
        r.push_back(numb[nums.size()-2]);
        for (int i=1;i<nums.size();i++) {
            if (i==nums.size()-1)
                r.push_back(numf[i-1]);
            else {
                r.push_back(numf[i-1]*numb[nums.size()-i-2]);
            }
        }
        return r;
    }
};
