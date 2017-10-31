/*
Date: 2016-09-23
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1)
            return 0;
        int a[10000][2];
        memset(a, 0, sizeof(int)*20000);
        a[0][0] = -1*prices[0];
        int ans=0;
        for (int i=1;i<prices.size();i++) {
            //0 for buy    1 for sell
            a[i][0] = max(a[i-1][0]+prices[i-1]-prices[i], (i-2<0?0:a[i-2][1])-prices[i]);
            a[i][1] = max(a[i-1][1]+prices[i]-prices[i-1], a[i-1][0]+prices[i]);
            if (a[i][1]>ans)
                ans=a[i][1];
        }
        return ans;
    }
};
