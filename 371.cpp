/*
Date: 2016-09-13
*/
class Solution {
public:
    int getSum(int a, int b) {
    int ca,cb;
    ca=a;
    cb=b;
    while (cb!=0) {
        int caa = ca^cb;
        cb  = ca&cb;
        if (cb!=0) {
            cb=cb<<1;
        }
        ca = caa;
    }
    return ca;
}
};
