/*
Date: 2016-09-22
*/
#include <stack>
class Solution {
public:
    void gen(int total, int lp, int rp) {
        if (lp == rp && rp == total) {
            string ss;
            for (auto a: s)
                ss = ss+a;
            r.push_back(ss);
            return;
        }
        else {
            if (lp<total) {
                s.push_back('(');
                gen(total, lp+1, rp);
                s.pop_back();
                if (lp>rp) {
                    s.push_back(')');
                    gen(total, lp, rp+1);
                    s.pop_back();
                }
            }
            else if (lp==total) {
                s.push_back(')');
                gen(total, lp, rp+1);
                s.pop_back();
            }
            return;
        }
    }

    vector<string> generateParenthesis(int n) {
        gen(n,0,0);
        return r;
    }
private:
    vector<string> r;
    vector<char> s;
};
