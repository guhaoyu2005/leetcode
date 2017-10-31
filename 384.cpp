/*
Date: 2016-09-15
*/
class Solution {
public:
    Solution(vector<int> nums) {
        orig = nums;
        arr = orig;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = orig;
        return arr;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> r;
        while (arr.size()>0) {
            int i= rand()%arr.size();
            r.push_back(arr[i]);
            arr.erase(arr.begin()+i);
        }
        arr=r;
        return r;
    }
private:
    vector<int> orig;
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
