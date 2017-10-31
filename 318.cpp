/*
Date: 2016-09-20
*/
/*
#include <vector>
#include <iostream>
#include <string>
using namespace std;
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
            bool bitFlag[26];
            int ans=0;
            vector<int> v;
            for (int i=0;i<words.size();i++) {
                memset(bitFlag, 0, sizeof(bool)*26);
                //fill(bitFlag, bitFlag+26, 0);
                int currV=0;
                for (int j=0;j<words[i].length();j++) {
                    if (!bitFlag[words[i][j]-97]) {
                        //cout<<words[i][j]<<"ASC:  "<<words[i][j]<<"   ";
                        bitFlag[words[i][j]-97] = 1;
                        currV+=bit[words[i][j]-97];
                    }
                    //cout<<endl;
                }
                //cout<<"I: "<<i<<"   Val: "<<currV<<endl;
                v.push_back(currV);
            }
            for (int i=0;i<words.size();i++) {
                for (int j=i+1;j<words.size();j++) {
                    if ((v[i]&v[j])==0){
                        //cout<<"i: "<<i<<"   j: "<<j<<endl;
                        //<<v[i]<<"======="<<v[j]<<endl<<endl;
                        if (words[i].length()*words[j].length()>ans)
                            ans= words[i].length()*words[j].length();
                    }
                }
            }
            return ans;
    }

private:
    int bit[26]= {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096,
                  8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
                  2097152, 4194304, 8388608, 16777216, 33554432};
};

/*
int main() {
    Solution sol;
    vector<string> foo;
    foo.push_back("abcw");
    foo.push_back("baz");
    foo.push_back("foo");
    foo.push_back("bar");
    foo.push_back("xtfn");
    foo.push_back("abcdef");
    cout<<sol.maxProduct(foo);
    return 0;
}
*/
