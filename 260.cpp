/*
Date: 2016-09-14
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r;
        for (auto i: nums)
            r=r^i;
        int rshift=0;
        for (int i=0;i<32;i++) {
            if ((i==0?i:r>>i)&1 == 1) {
                rshift=i;
                break;
            }
        }
        int a,b;
        a=0;
        b=0;
        for (auto i: nums) {
            if ((rshift==0?i: i>>rshift)&1==1)
                a=a^i;
            else
                b=b^i;
        }
        return vector<int>{a, b};
    }
};
