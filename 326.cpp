/*
Date: 2016-09-23
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        double r = log10(n)/log10(3);
        return n<=0?0:r-int(r)==0;
    }
};
