/*
Date: 2016-09-22
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
            bool a[1100][1100];
            int distK, dist;
            memset(a, 0, sizeof(bool)*1100*1100);
            a[0][0] = 1;
            int maxGap=sqrt(stones[stones.size()-1]*2)+1;
            if (stones[1]==1) {
                a[1][0] = 1;
                if (stones.size()==2)
                    return true;
            }
            else
                return false;
            for (int i=2;i<stones.size();i++) {
                for (int j=i-1;j>0;j--) {
                    dist = stones[i]-stones[j];
                    if (dist>maxGap)
                        break;
                    if (dist>stones[i]/2+1)
                        break;
                    if (dist>stones[stones.size()-1]-stones[j])
                        break;
                    if (dist>i)
                        break;
                    for (int k=j-1;k>=0;k--) {
                        distK = stones[j] - stones[k];
                        if (distK>dist+1)
                            break;
                        if (!a[j][k])
                            continue;
                        if (abs(distK-dist)<=1) {
                            a[i][j] = true;
                            break;
                        }
                    }
                    if (i==stones.size()-1 && a[i][j])
                        return true;
                }
            }
            return false;
    }
};
