/*
Date: 2016-10-18
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int maxx = -1;
        int maxy = -1;
        if (matrix.size()==0)
            return false;
        if (matrix[0].size()==0)
            return false;
        for (int i=0;i<matrix[0].size();i++) {
            if (matrix[0][i]==target)
                return true;
            if (matrix[0][i]>target) {
                if (i-1<0)
                    return false;
                maxy = i-1;
                break;
            }
        }
        if (maxy==-1)
            maxy = matrix[0].size()-1;
        for (int i=0;i<matrix.size();i++) {
            if (matrix[i][0]==target)
                return true;
            if (matrix[i][0]>target) {
                if (i-1<0)
                    return false;
                maxx = i-1;
                break;
            }
        }
        if (maxx==-1)
            maxx = matrix.size()-1;
        for (int i=maxx;i>=0;i--) {
            for (int j=maxy;j>=0;j--) {
                if (matrix[i][j]==target)
                    return true;
                if (matrix[i][j]<target)
                    break;
            }
        }
        return false;
    }
};
