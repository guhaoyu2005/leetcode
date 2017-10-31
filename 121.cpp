/*
Date: 2016-09-15
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        if (prices.size()==0)
            return 0;
        vector<int> a;
        a.push_back(prices[0]);
        for (int i=1;i<prices.size();i++) {
            a.push_back((prices[i]>a[i-1]? a[i-1]:prices[i]));
            result = (result>(prices[i]-a[i])? result:(prices[i]-a[i]));
        }
        return result;
    }
};
