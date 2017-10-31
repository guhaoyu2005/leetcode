/*
Date: 2016-09-16
*/
class Solution {
public:
    int integerBreak(int n) {
        int a[60];
        std::fill(a, a+58, 0);
        a[1]=1;
        a[2]=2;
        a[3]=3;
        for (int i=4;i<=n;i++) {
            int max=0;
            for (int j=i-1;j>=1;j--) {
                int c = a[j]*(i-j);
                if (c>max)
                    max= c;
            }
            a[i]= max;
        }
        return n==2?1:(n==3?2:a[n]);
    }
};
