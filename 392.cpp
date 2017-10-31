/*
Date: 2016-09-16
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s=="")
            return true;
        bool r= false;
        int a[1000000];
        std::fill(a, a+1000000, 0);
        if (s[0]==t[0])
            a[0]=0;
        for (int i=1;i<t.length();i++) {
            if (t[i]==s[a[i-1]+1]) {
                a[i]=a[i-1]+1;
            }
            else {
                a[i]=a[i-1];
            }
            if (a[i]==s.length()-1){
                r= true;
                break;
            }
        }
        return r;
    }
};
