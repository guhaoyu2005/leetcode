/*
Date: 2016-09-27
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int r =0;
        for (int i=0;i<32;i++) {
            r+=n&1;
            n=n>>1;
        }
        return r;
    }
};
