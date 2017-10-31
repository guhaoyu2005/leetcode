/*
Date: 2016-09-27
*/
class Solution {
public:
    bool isUgly(int num) {
        if (num<=0)
            return false;
        int n= num;
        while (n>1) {
            int flag=0;
            if (n%5==0) {
                n/=5;
                flag++;
            }
            if (n%3==0) {
                n/=3;
                flag++;
            }
            if (n%2==0) {
                n=n>>1;
                flag++;
            }
            if (flag==0)
                return false;
        }
        return true;
    }
};
