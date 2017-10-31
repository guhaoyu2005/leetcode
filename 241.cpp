/*
Date: 2016-09-23
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> r;
        for (int i=0;i<input.length();i++) {
            if (input[i]>=42 && input[i]<=45) {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                int sym = input[i]-42;
                for (int j=0;j<left.size();j++) {
                    for (int k=0;k<right.size();k++) {
                        int a = ((sym==0)?left[j]*right[k]:(sym==1?left[j]+right[k]:left[j]-right[k]));
                        r.push_back(a);
                    }
                }
            }
        }
        if (r.empty())
            r.push_back(atoi(input.c_str()));
        return r;
    }
};
