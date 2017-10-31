/*
Date: 2016-09-15
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letter[26];
        fill(letter, letter+26, 0);
        for (int i=0;i<ransomNote.length();i++)
            letter[ransomNote[i]-97]++;
        for (int i=0;i<magazine.length();i++)
            letter[magazine[i]-97]--;
        for (int i=0;i<26;i++)
            if (letter[i]>0)
                return false;
        return true;
    }
};
