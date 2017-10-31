/*
Date: 2016-09-21
*/
#include <stdlib.h>
#include <algorithm>
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size()==0)
            return 0;
        vector<int> num;
        for (auto i: nums)
            num.push_back(i);
        make_heap(num.begin(), num.end());
        sort_heap(num.begin(), num.end());
        int arr[200000];
        memset(arr, 0 ,sizeof(int)*200000);
        arr[num[0]] = 1;
        for (int i=1;i<=target;i++) {
            int curr = 0;
            for (int j=0;j<num.size();j++) {
                if (num[j]>i)
                    break;
                if (num[j]==i) {
                    curr++;
                    break;
                }
                curr+=arr[i-num[j]];
            }
            arr[i] = curr;
        }
        return arr[target];
    }
};
