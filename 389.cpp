/*
Date: 2016-09-14
*/
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int f[26];
        fill(f, f+26, 0);
        for (int i=0;i<t.length();i++)
            f[t[i]-97]++;
        for (int i=0;i<s.length();i++)
            f[s[i]-97]--;
        for (int i=0;i<26;i++)
            if (f[i]!=0) {
                    char r = i+97;
                    return r;
            }
        return '0';
    }
};
