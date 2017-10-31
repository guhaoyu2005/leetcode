/*
Date: 2016-09-20
*/
class Solution {
public:
    int max(int a, int b) {
        return a>b?a:b;
    }

    int maxCoins(vector<int>& nums) {
        int f[502][502];
        int a[502];
        memset(f, 0, sizeof(int)*502*502);
        for (int i=1;i<=nums.size();i++)
            a[i] = nums[i-1];
        a[0] = 1;
        a[nums.size()+1] = 1;
        for (int i=1;i<=nums.size();i++) {  //length for each
            for (int j=1;j<=nums.size()-i+1;j++) {  //starting point
                for (int k=j;k<=j+i-1;k++) { //loop the last result arr
                    f[j][j+i-1] = max(f[j][j+i-1],
                        f[j][k-1]+f[k+1][j+i-1]+a[j-1]*a[k]*a[j+i]);
                }
            }
        }
        return f[1][nums.size()];
    }
};
