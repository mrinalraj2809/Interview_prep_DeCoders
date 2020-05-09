/***************************************************
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
***************************************************/
/* Brute Force approch */
class Solution {
public:
    vector<unsigned long long int> v;
    Solution(): v(100000)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        for(unsigned int i=0;i<v.size();i++)
        {
            v[i] = i * i;
        }
    }
    bool isPerfectSquare(int num) {
        if(find(v.begin(),v.end(),num)!=v.end())return true;
        return false;
    }
};
/**** Efficient approch ******/
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1){
            return true;
        }
        int l=0, h=num/2;
        
        while(l<=h){
            long long int mid=(l+h)/2;
            
            cout<<mid<<endl;
            long long int ans=mid*mid;
            if(ans==num){
                return true;
            }
            else if(ans < num)
                l=mid+1;
            else
                h=mid-1;
        }
        
        return false;