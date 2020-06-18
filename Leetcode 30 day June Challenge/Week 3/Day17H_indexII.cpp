/**********************************************************************************
 H-Index II

Solution
Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
Note:

If there are several possible values for h, the maximum one is taken as the h-index.

Follow up:

This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?
**********************************************************************************/
First we will look at O(N) solution to understand the problem then we will optimise it with binary search.

The Idea behind the problem
Let us consider the following example:

[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Here the ans is 6.

Why not 5 or 7?

number of papers with citation alteast 7 is only 5.
Wheras for 6 it is 6 i.e. among 12 papers 6 papers have citation atleast 6.

And though number of paper with citation atleast 5 is more than that of 6, 6 is higher value compared to 5 and also the quantity 6 is a better tradeoff.

The key concept here is to understand that the problem requires a value that has a proper weight with significant quantity.

One more observation we can make here is that more consecutive integers the value at the middle is good as the quantity and weight is bettered compared to other elements.
The O(N) approach:

This approach is straight forward traverse the array and when you find the first element such that the value of that element is greater than or equal to the amount of elements remaining that is our ans so we return the length of array after that point. If no such element exisits return 0;

CODE:

int hIndex(vector<int>& c) {
        int n = c.size();
        if(!n) return 0;
        for(int i=0;i<n;i++){
             if(c[i] >= n-i) return n-i;   // The first element whose value is more than the length of remaining array. 
			 //So we return the remaining length which is the answer.
			 // eg [0,1,3,4,6]  c[2] = 3 >2(length of remaing array) so n-i = length of remaining array + that element
        }
        return 0;
    }
The O(logn) approach | Binary Search

It is clear now that we need to find such an element as discussed in O(n) solution but faster so we need binary search. We will store our answer in ans variable. Once our condition is hit we store the length of remaing array on ans and continue with our binary search as we want the first element that satisfies this condition.
// O(n) approach 
int hIndex(vector<int>& c) {
        int n = c.size();
        if(!n) return 0;
        for(int i=0;i<n;i++){
             if(c[i] >= n-i) return n-i;   // The first element whose value is more than the length of remaining array. 
			 //So we return the remaining length which is the answer.
			 // eg [0,1,3,4,6]  c[2] = 3 >2(length of remaing array) so n-i = length of remaining array + that element
        }
        return 0;
    }

// log (n) approach 
class Solution {
public:
    int hIndex(vector<int>& c) {
         int n = c.size();
        if(!n) return 0;
        int low =0,high=n-1;
        int ans = 0;
        while(low<=high){
            int mid  = low + (high-low)/2;
            if(c[mid] >= n-mid){
                ans = n-mid;
                high = mid - 1;
            }else{
                low  = mid + 1;
            }
        }
        
        return ans;
    }
};