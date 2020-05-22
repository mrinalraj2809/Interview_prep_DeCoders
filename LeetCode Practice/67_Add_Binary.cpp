/**************Add Binary ***************************
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*****************************************/


class Solution {
public:
    string addBinary(string a, string b) {
        long long int i=a.length()-1;long long int j=b.length()-1;int carry=0;string res="";int temp=0;
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        while(i>-1 && j >-1)
        {
            temp = (carry + a[i]  - '0'+  b[j]-'0' )%2;
            carry = (carry + a[i] + b[j] - '0' -'0' )/2;
            res = to_string(temp) + res;
            i--;j--;
        }
        while(i>-1)
        {
            temp = (carry + a[i]  - '0' )%2;
            carry = (carry + a[i] - '0'   )/2;
            res = to_string(temp) + res;
            i--;
        }
        while(j>-1)
        {
            temp = (carry + b[j] - '0'  )%2;
            carry = (carry + b[j] - '0' )/2;
            res = to_string(temp) + res;
            j--;
        }
        if(carry!=0)
        res = to_string(carry) + res;
        return res;
    }
};