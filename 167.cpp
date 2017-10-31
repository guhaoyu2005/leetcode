/*
Date: 2016-09-14
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1,p2;
        p1=0;
        p2=numbers.size()-1;
        while (numbers[p1]+numbers[p2]!=target) {
            while (numbers[p1]+numbers[p2]>target)
                p2--;
            while (numbers[p1]+numbers[p2]<target)
                p1++;
        }
        return vector<int>{p1+1, p2+1};

    }
};
