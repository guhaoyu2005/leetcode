/*
Date: 2016-09-16
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int a[26][2];
        memset(&a, 0, sizeof(int)*26*2);
        for (int i=0;i<s.length();i++) {
            a[s[i]-97][0]=i;
            a[s[i]-97][1]++;
        }
        int r = -1;
        int loc = 99999999;
        for (int i=0;i<26;i++)
            if (a[i][1]==1 && a[i][0]<loc) {
                r = a[i][0];
                loc = a[i][0];
            }
        return r;
    }
};
