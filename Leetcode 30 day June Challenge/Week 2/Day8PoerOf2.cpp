/*****************************************************************************
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
******************************************************************************/

// runtime 2 ms
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int setbits=0;
        while(n){
            setbits++;
            n = n & (n-1);
        }
        return setbits==1;
    }
};

//Approach 2: Precomputation
class Solution {
public:

    
    vector<double> powTable;
    Solution()
    {
        constructPowTable();
    }
    typedef unsigned long long int ull;
    void fast()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    }
    void constructPowTable()
    {
        
        for(ull i=0;i<1000;i++)
        {
            powTable.push_back((pow(2,i)));
        }
    }
    bool isPowerOfTwo(int n) {
        fast();
        if(n<0)return false;
        double num=n;
        if(find(powTable.begin(),powTable.end(),num)!=powTable.end())return true;
        return false;
        
    }
};