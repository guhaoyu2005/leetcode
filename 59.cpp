/*
Date: 2016-10-05
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n==0)
            return {};
        int r[1000][1000];
        int vertCtl = 0;
        int horiCtl = 1;
        int curr = 1;
        int currX = 1;
        int currY = 1;
        memset(r, 0, sizeof(int)*900*900);
        while (curr<=n*n) {
            r[currY][currX] = curr;
            if ((currX>=n || r[currY][currX+1]!=0) && vertCtl==0 && horiCtl==1) {
                vertCtl = 1;
                horiCtl = 0;
            }
            else if ((currY>=n || r[currY+1][currX]!=0) && horiCtl==0 && vertCtl==1) {
                vertCtl = 0;
                horiCtl = -1;
            }
            else if ((currX<=1 || r[currY][currX-1]!=0) && vertCtl==0 && horiCtl==-1) {
                vertCtl = -1;
                horiCtl = 0;
            }
            else if ((currY<=1 || r[currY-1][currX]!=0) && horiCtl==0 && vertCtl==-1) {
                vertCtl = 0;
                horiCtl = 1;
            }
            currX+=horiCtl;
            currY+=vertCtl;
            curr++;
        }
        vector<vector<int>> rr;
        for (int i=1;i<=n;i++) {
            vector<int> t;
            for (int j=1;j<=n;j++)
                t.push_back(r[i][j]);
            rr.push_back(t);
        }
        return rr;
    }
};
