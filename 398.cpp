//Date: 2016-11-08
class Solution {
public:
    //map<int, vector<int>> m;
    vector<int> m;
    Solution(vector<int> nums) {
            m = nums;
            srand(time(NULL));
    }

    int pick(int target) {
        int n=0;
        int ans=0;
        for (int i=0;i<m.size();i++) {
            if (m[i]==target) {
                n++;
                if (n==1) {
                    ans = i;
                }
                else
                    ans = (rand()%n==0)? i: ans;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
