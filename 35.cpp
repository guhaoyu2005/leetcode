/*
Date: 2016-09-23
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l,r;
        l=0;
        r=nums.size()-1;
        while (l<=r) {
            if (l==r)
                if (nums[l]<target)
                    return l+1;
                else
                    return l;
            int mid = nums[(l+r)/2];
            if (mid==target)
                return (l+r)/2;
            else if (mid<target) {
                l=(l+r)/2+1;
            }
            else if (mid>target) {
                r=(l+r)/2;
            }
        }
        return 0;
    }
};
