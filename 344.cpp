/*
Date: 2016-09-13
*/
class Solution {
public:
    string reverseString(string s) {
        string r = "";
        for (int i= s.length();i>0;i--)
            r=r+s[i-1];
        return r;
    }
};
