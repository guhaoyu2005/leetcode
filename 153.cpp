/*
Date: 2016-09-27
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()>1) {
            int l, r;
            l=0;
            r=nums.size()-1;
            while (l<=r) {
                if (nums[(l+r)/2]<=nums[r]) {
                    if ((l+r)/2==0)
                        return nums[(l+r)/2];
                    else {
                        if (nums[(l+r)/2-1]<=nums[(l+r)/2]){
                            r=(l+r)/2-1;
                        }
                        else {
                            return nums[(l+r)/2];
                        }
                    }
                }
                else {
                    if ((l+r)/2==nums.size()-1)
                        return nums[(l+r)/2];
                    else {
                        if (nums[(l+r)/2+1]>nums[(l+r)/2]) {
                            l=(l+r)/2+1;
                        }
                        else {
                            return nums[(l+r)/2+1];
                        }
                    }
                }
            }
        }
        else
            return nums[0];
        return -1;
    }
};
