/*
Date: 2016-10-05
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num<=-1) {
            return false;
        }
        if (num<=1) {
            return true;
        }
        int i=1;
        while (i<=num/2) {
            if (i*i>num)
                return false;
            else if (i*i==num)
                return true;
            if (i*i<=num/4){
                i*=2;
            }
            else
                i++;
        }
        return false;
        /*
        int l=1;
        int r=num;
        int mid, rr;
        while (l<r) {
            mid = (l+r)>>1;
            rr = mid*mid;
            if (rr==num)
                return true;
            if ((l+1)==r)
                if ((l*l<num) && (r*r>num))
                    return false;
            if (rr<num) {
                l = mid;
            }
            else {
                if (num/rr>=2) {
                    r = mid/2;
                }
                else
                    r = mid-1;
            }
        }
        return false;
        */
    }
};
