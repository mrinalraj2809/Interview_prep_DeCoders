/**************************************************************************************************************
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
***************************************************************************************************************/
// using next permutation
class Solution {
public:
    // vector<string> res;
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
    }
//     void permute(string a, int l, int r, int k)
//     {
//         if(l==r) res.push_back(a);
//         else if(k == res.size()){return ;}
//         else
//         {
//             for(int i = l; i<= r; i++)
//             {
//                 swap(a[l], a[i]);
//                 permute(a, l+1, r, k);
//                 swap(a[l], a[i]);
//             }
//         }
        
//     }
    string getPermutation(int n, int k) {
//         string num = "";
//         res.clear();
//         for(int i=1;i<=n;i++)
//         {
//             num += to_string(i);
//         }
        
//         permute(num,0,n-1,k);
//         sort(res.begin(),res.end());
//         return res[k-1];
        // {
        bool ans = false;
        string s = "";
        for(int i=1;i<=n;i++)
        {
            char c =(char)(i + '0');
            s+=c;
        }

        for(int j=1;j<k;j++)
        {
            next_permutation(s.begin(),s.end());
        }

        return s;
    }
};

// Best Approach
class Solution {
public:
    string getPermutation(int n, int k) {
      vector<char> nums;
      int factorial = 1;
      for (int i = 1; i <= n; ++i) {
        factorial *= i;
        nums.push_back(i + '0');
      }
      k--;
      string res;
      while (n) {
        factorial /= n;
        int digit = k / factorial;
        res.push_back(nums[digit]);
        nums.erase(nums.begin() + digit);
        n--;
        k %= factorial;
      }
      return res;
    }
};