/***************************************************
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
***************************************************/

/************** Solution cpp ***************/
Approach 1: Runtime 12ms
class Solution {
public:
    bool checkInclusion(string p/*s1*/, string s/*s2*/) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        vector<int> sv(26, 0);
        vector<int> pv(26, 0);
        vector<int> res;
        
        // hash pattern whoes permutation is to be found.
        for (auto c : p)
            pv[c - 'a']++;
        
        for (int i = 0; i < s.size(); i++) {
            sv[s[i] - 'a']++;
            if (i >= p.size())
                sv[s[i - p.size()] - 'a']--;
            if (sv == pv)
                return true;
        }
        
        return false;
    }
};
