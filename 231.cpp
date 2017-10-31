/*
Date: 2016-09-23
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0)
            return false;
        return !(n&(n-1));
    }
};
