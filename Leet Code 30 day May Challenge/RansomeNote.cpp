/******************* Ransome Note **************************
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*************************************************************/

/************ Solution cpp *********************/

/***** Brute Force Approch ****/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        set<char> ranNote;
        for(int i=0;i<ransomNote.length();i++)
        {
            ranNote.insert(ransomNote[i]);
        }
        for(auto it = ranNote.begin();it!=ranNote.end();it++ )
        {
            int c1 = count(ransomNote.begin(),ransomNote.end(),*it);
            int c2 = count(magazine.begin(),magazine.end(),*it);cout<<c1<<" "<<c2<<"\n";
            if(c1 > c2)return false;
        }
        return true;
        
    }
};



/*    Efficient approch  **/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for(char i: magazine)
            v[i-'a']++;
        for(char j: ransomNote)
            if(--v[j-'a']<0) return false;
        return true;
        
    }
};