/*
Date: 2016-09-16
*/
class Solution {
public:
    string convertToTitle(int n) {
        string result="";
        int a = n;
        int b;
        while (true) {
            int b= a%26;
            int tmp = a/26;
            result = (char)((b==0?26:b)+64)+result;
            if (tmp==0 || (tmp==1&&b==0))
                break;
            else {
                a= tmp==1?1:tmp-(b==0?1:0);
            }
        }

        return result;
    }
};
