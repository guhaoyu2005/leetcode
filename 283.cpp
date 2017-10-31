/*
Date: 2016-09-14
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=0;
        int lastZero=-1;
        while (p!=nums.size()) {
            if (nums[p]==0) {
                if (lastZero==-1)
                    lastZero=p;
                p++;
            }
            else {
                if (lastZero==-1)
                    p++;
                else {
                    int tmp= nums[p];
                    nums[p]=0;
                    nums[lastZero]= tmp;
                    p=lastZero+1;
                    lastZero=-1;
                }
            }
        }
    }
};
