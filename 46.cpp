/*
Date: 2016-09-23
*/
class Solution {
public:
    void work(vector<int>& nums, vector<int>& r) {
        if (nums.size()==0) {
            rr.push_back(r);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            int c = nums[i];
            r.push_back(c);
            vector<int> num = nums;
            num.erase(num.begin()+i);
            work(num ,r);
            r.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size()==0)
            return rr;
        work(nums, r);
        return rr;
    }
private:
    vector<int> r;
    vector<vector<int>> rr;
};
