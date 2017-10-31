/*
Date:2016-09-20
*/
class Solution {
public:
    bool checkVert(int x, int y) {
        for (int i=1;i<=scale;i++) {
            if (i==y)
                continue;
            else
                if (b[x][i])
                    return false;
        }
        return true;
    }

    bool checkHoriz(int x, int y) {
        for (int i=1;i<=scale;i++) {
            if (i==x)
                continue;
            else
                if (b[i][y])
                    return false;
        }
        return true;
    }

    bool checkSlo(int x, int y) {
        //check 4 directions
        //1 LT, 2 LD, 3 RT, 4 RD
        int step[4][2] = {{-1,-1}, {-1, 1}, {1,-1}, {1, 1}};
        int i=0;
        while (i<4) {
            int cx=x;
            int cy=y;
            while (cx>0 && cx<=scale && cy>0 && cy<=scale) {
                    cx+=step[i][0];
                    cy+=step[i][1];
                    if (b[cx][cy])
                        return false;
            }
            i++;
        }
        return true;
    }

    void putNext(int col) {
        if (col>scale) {
            ans++;
            return;
        }
        else {
            for (int i=1;i<=scale;i++) {
                b[col][i] = 1;
                if (checkVert(col, i) && checkHoriz(col, i) && checkSlo(col, i)) {
                    putNext(col+1);
                }
                b[col][i] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        scale = n;
        putNext(1);
        return ans;
    }
private:
    int scale;
    bool b[15][15];
    int ans=0;
};
