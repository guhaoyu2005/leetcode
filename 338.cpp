/*
Date: 2016-09-13
*/
#include <math.h>

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        if (num>=1)
            result.push_back(1);
        int cnt=0;
        long ele=2;
        long nx=2;
        for (int i=2;i<=num;i++) {
            if (i==nx) {
                cnt++;
                ele=pow(2, cnt);
                nx=pow(2, cnt+1);
            }
            result.push_back(1+result.at(i-ele));
        }
        return result;
    }
};
