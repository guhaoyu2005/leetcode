/*
Date: 2016-09-16
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26];
        std::fill(a, a+26, 0);
        for (int i=0;i<s.length();i++) {
            a[s[i]-97]++;
        }
        for (int i=0;i<t.length();i++) {
            a[t[i]-97]--;
        }
        for (int i=0;i<26;i++) {
            if (a[i]!=0)
                return false;
        }
        return true;
    }
};
