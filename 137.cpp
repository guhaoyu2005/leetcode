/*
Date: 2016-09-22
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32];
        memset(bit, 0, sizeof(int)*32);
        for (auto i: nums) {
            int j=i;
            for (int k=0;k<32;k++) {
                bit[k]+=j&1;
                j=j>>1;
                if (j==0)
                    break;
            }
        }
        int r = 0;
        for (int i=31;i>=0;i--) {
            if (bit[i]%3!=0)
                r++;
            if (i!=0)
                r=r<<1;
        }
        return r;
    }
};
