Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


/***************** Solution cpp  *******************/
// runtime 44ms
class Solution {
public:
    string trimZero(string s)
    {
        if(s.length()==0)return "0";
        else if(s[0] != '0')return s;
        return trimZero(s.substr(1));
    }
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin.tie(0);
        string::size_type sz;
        if(num.length() == k)return "0";
        stack<char> s;s.push(num[0]);
        for(int i=1;i<num.size();i++)
        {
            while( k>0 &&  !s.empty() && s.top() > num[i])
            {
                s.pop(); k--;
            }
            s.push(num[i]);
        }
        while(k--!=0)s.pop();
        string res="";
        while(!s.empty())
        {
            res = s.top() + res;
            s.pop();
        }
        
        return trimZero(res);
        
    }
};

// Approach 2 : runtime 4ms
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;
        if(k == num.length()) return "0";
        string ans = "";
        int l = k;
        for(int i = 0; i < num.length(); i++) {
            while(k && ans.length() && ans.back() > num[i]) {
                k--;
                ans.pop_back();
            }
            ans += num[i];
        }
        ans.resize(num.length()-l);
        int x = 0;
        while(x < ans.length() && ans[x] == '0') x++;
        if(x == ans.length()) return "0";
        return ans.substr(x);
    }
};
