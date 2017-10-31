/*
Date: 2016-09-19
*/
#include <sstream>
class Solution {
public:
    void foo(int numLeft, int offset) {
        if (numLeft==0) {
            int h= 0;
            int m= 0;
            for (int i=0;i<4;i++)
                h+=bit[i]?v[i]:0;
            if (h>11)
                return;
            for (int i=4;i<10;i++)
                m+=bit[i]?v[i]:0;
            if (m>=60)
                return;
            ostringstream o;
            o.clear();
            o<<h<<":"<<(m<10?"0":"")<<m;
            r.push_back(o.str());
            return;
        }
        if (offset+numLeft>10)
            return;
        else {
            for (int i=offset;i<10;i++) {
                bit[i]=1;
                foo(numLeft-1, i+1);
                bit[i]=0;
            }
        }
    }

    vector<string> readBinaryWatch(int num) {
        n = num;
        memset(bit, sizeof(bool)*10, 0);
        if (num!=0) {
            for (int i=0;i<10;i++) {
                bit[i]=1;
                foo(num-1, i+1);
                bit[i]=0;
            }
        }
        else
            r.push_back("0:00");
        return r;
    }

private:
    const int v[10] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    vector<string> r;
    bool bit[10];
    int n;
};
