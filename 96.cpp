/*
Date: 2016-09-23
*/
class Solution {
public:
    int numTrees(int n) {
        int a[100000];
        memset(a, 0, sizeof(int)*100000);
        a[0]=1;
        a[1]=1;
        for (int i=2;i<=n;i++) {
            int ans=0;
            for (int j=1;j<=i/2;j++) {
                ans+=a[j-1]*a[i-j];
            }
            ans*=2;
            if (i%2)
                ans+=a[i/2]*a[i/2];
            a[i]=ans;
        }
        return a[n];
    }
};
