/*
Date: 2016-09-27
*/
class Solution {
public:
    int climbStairs(int n) {
        int arr[100000];
        memset(arr, 0, sizeof(int)*100000);
        arr[0]=1;
        arr[1]=2;
        for (int i=2;i<n;i++) {
            arr[i] = arr[i-2]+arr[i-1];
        }
        return arr[n-1];
    }
};
