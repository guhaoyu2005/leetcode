/*
Date: 2016-09-16
*/
#include <math.h>
class Solution {
public:
    int titleToNumber(string s) {
        int ans= 0;
        for (int i=0;i<s.length();i++) {
            ans+=(s[i]-64)*pow(((i!=s.length()-1)?26:1), s.length()-1-i);
        }

        return ans;
    }
};
