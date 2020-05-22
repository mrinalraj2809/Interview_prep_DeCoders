/******************** Add String ************************************
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

**********************************************************************/
class Solution {
public:
    string addStrings(string num1, string num2) {
        long long int i=num1.length()-1;long long int j=num2.length()-1;int carry=0;string res="";int temp=0;
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        while(i>-1 && j >-1)
        {
            temp = (carry + num1[i]  - '0'+  num2[j]-'0' )%10;
            carry = (carry + num1[i] + num2[j] - '0' -'0' )/10;
            res = to_string(temp) + res;
            i--;j--;
        }
        while(i>-1)
        {
            temp = (carry + num1[i]  - '0' )%10;
            carry = (carry + num1[i] - '0'   )/10;
            res = to_string(temp) + res;
            i--;
        }
        while(j>-1)
        {
            temp = (carry + num2[j] - '0'  )%10;
            carry = (carry + num2[j] - '0' )/10;
            res = to_string(temp) + res;
            j--;
        }
        if(carry!=0)
        res = to_string(carry) + res;
        return res;
    }
};