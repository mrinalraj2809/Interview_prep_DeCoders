/****************************************Longest Duplicate Substring *******************************************
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
   Hide Hint #1  
Binary search for the length of the answer. (If there's an answer of length 10, then there are answers of length 9, 8, 7, ...)
   Hide Hint #2  
To check whether an answer of length K exists, we can use Rabin-Karp 's algorithm.
********************************************************************************************************/
class Solution {
public:
    string longestDupSubstring(string s) {
       string longest;
        std::unordered_set<std::string_view> set;
        size_t beg = 1;
        size_t end = S.size() - 1;
        while (beg <= end)
        {
            auto len = beg + (end - beg) / 2;
            bool found = false;
            for (size_t i = 0; i != S.size() - len + 1; ++i)
            {
                const auto [it, inserted] = set.emplace(S.data() + i, len);
                if (!inserted)
                {
                    found = true;
                    longest = std::move(*it);
                    break;   
                }
            }
            
            if (found)
                beg = len + 1;
            else
                end = len - 1;
            
            set.clear();      
        }
            
        return longest;
};