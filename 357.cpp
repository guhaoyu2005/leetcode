/*
Date: 2016-09-16
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int a[100000];
        a[0]=1;
        a[1]=10;
        for (int i=2;i<=n;i++) {
            int base=11-i;
            int count =9;
            if (base<=0)
                base=1;
            for (int j=9;j>=base;j--)
                count*=j;
            a[n]=a[n-1]+count;
        }
        return (n==1?10:a[n]);
    }
};
