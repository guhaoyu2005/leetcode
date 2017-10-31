/*
Date: 2016-09-26
*/
class Solution {
public:
    void calc(int n, int max) {
        int st = pow(2, n-1)+max/2;
        for (int i=0;i<max/2;i++) {
            ans.push_back(st+ans[i]);
        }
        for (int i=0;i<max/2;i++) {
            ans.push_back(max+ans[max/2-i-1]);
        }
    }

    vector<int> grayCode(int n) {
        if (n>=0)
            ans.push_back(0);
        if (n>=1)
            ans.push_back(1);
        if (n>=2) {
            ans.push_back(3);
            ans.push_back(2);
        }
        for (int i=3;i<=n;i++) {
            calc(i, pow(2, i-1));
        }
        return ans;
    }
private:
    vector<int> ans;
};
