/*
Date: 2016-09-23
*/
class Solution {
public:
    string decodeString(string s) {
        string r="";
        int times=0;
        int i=0;
        if (s[0]>=48 && s[0]<=57) {
            while (i<s.length()) {
                if (s[i]=='[')
                    break;
                times = times*10+ (s[i]-48);
                i++;
            }
            i++;
            int st = i;
            int lb=1;
            while (lb!=0) {
                if (s[i]=='[')
                    lb++;
                if (s[i]==']')
                    lb--;
                i++;
            }
            string rr = decodeString(s.substr(st, i-st));
            for (int j=0;j<times; j++)
                r+=rr;
            if (i<s.length()) {
                r+=decodeString(s.substr(i));
            }
        }
        else if (s[0]>=97 && s[0]<=122) {
            string pre = "";
            for (int j=0;j<s.length();j++) {
                if (s[j]>=97 && s[j]<=122)
                    pre+=s[j];
                else {
                    pre+=decodeString(s.substr(j));
                    break;
                }
            }
            r = pre;

        }
        return r;
    }
};
