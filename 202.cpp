/*
Date: 2016-09-26
*/
class Solution {
public:
    bool isHappy(int n) {
        int nn = n;
        int curr = 0;
        do {
            int cBit = nn%10;
            curr+=cBit*cBit;
            nn/=10;
        } while(nn>0);
        map<int, int>::iterator it = m.find(curr);
        if (it!=m.end())
            return false;
        else {
            m.insert(pair<int, int>(curr, 1));
        }
        if (curr==1)
            return true;
        else {
            return isHappy(curr);
        }
    }
private:
    map<int, int> m;
};
