/*
Date: 2016-09-22
*/
class Solution {
public:
    bool calc(int lastNum, int currSum, int k, int currK, int n) {
        bool noMore = false;
        if (k==currK) {
            if (currSum == n) {
                r.push_back(slot);
                return false;
            }
            else
                return currSum>n?false:true;
        }
        else {
            for (int i=lastNum+1;i<=9;i++) {
                slot.push_back(i);
                bool lr = calc(i, currSum+i, k, currK+1, n);
                slot.pop_back();
                if (i==lastNum && !lr)
                    noMore = true;
                if (!lr)
                    break;
            }
        }
        return !noMore;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for (int i=1;i<=9;i++) {
            slot.push_back(i);
            bool lr = calc(i, i, k, 1, n);
            slot.pop_back();
            if (!lr)
                break;
        }
        return r;
    }
private:
    vector<int> slot;
    vector<vector<int>> r;
};
