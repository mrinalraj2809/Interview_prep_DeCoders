/****************Sort Characters By frequency *********************
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
***************************************************/


// Approach 1: Runtime 44 ms
class Solution {
public:
    struct alphabet
    {
        int freq;
        char c;
        
    };
    
    static bool comparableAlphabet(alphabet x, alphabet y)
    {
        return x.freq>y.freq;
    }
    string frequencySort(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        vector<alphabet> a(256);
        for(int i=0;i<s.length();i++)
        {
            a[s[i] ].freq++;
            a[s[i] ].c = s[i];
        }
        sort(a.begin(),a.end(),comparableAlphabet);
        string res = "";
        for(int i=0;i<a.size();i++)
        {
            for(int j =0; j<a[i].freq;j++)
            {
                res += a[i].c;
            }
        }
        return res;
    }
};

// Approach 2: Runtime 24ms
class Solution {
public:
    struct Comp{
      bool operator()(pair<int,char> &a, pair<int,char> &b) {
          return a.first < b.first;
      }  
    };
    string frequencySort(string s) {
        vector<int> vec(128, 0);
        for (auto i: s) vec[i]++;
        
        vector<pair<int,char>> v;
        
        for (auto i = 0; i < 128; ++i) {
            if (vec[i]> 0) v.push_back({vec[i], i});
        }
        sort(v.rbegin(), v.rend());
        string ans = "";
        for (auto pair:v) {
            ans.append(pair.first, pair.second);
        }
        return ans;
        
    }
};