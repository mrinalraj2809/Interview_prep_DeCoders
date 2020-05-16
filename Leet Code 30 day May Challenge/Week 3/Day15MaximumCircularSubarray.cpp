/********************************************************************
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
********************************************************************/




/************ Solution cpp  *****************/
Explanation: Approach 1 runtime 92 ms
/**************************************** 
tsum is total sum of array.minn is minimum subarray sum of array and maxx is maximum subarray sum of the array.
The logic is simple if you remove the minimum from a total you get the maximum.

First find the maximum subarray sum in the straight array without considering circular behaviour.
to find the maximum circular subarray sum first find the minimum subarray sum of the array without considering circular behaviour.
maximum circular subarray sum will be equal to total sum - minimum subarray sum of the array.
Now the ans is maximum of maximum subarray sum and maximum subarray sum in circular behaviour
Also if the array is all negative elements(or you can say minn=tsum) then the answer is maximum subarray without circular - this is a boundary case which you neet to check.
For example array is [5,2,-3,-2,8]
maxx=10(maximum subarray sum)
minn=-5(minimum subarray sum)
tsum=10(total sum of array elements)
ans=maximum of(maxx,tsum-minn) = maximum(10,10-(-5)) = 15.
******************************************/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int maxx=INT_MIN,minn=INT_MAX,sum1=0,sum2=0,tsum=0;   
        for(auto x:A)
        {
            tsum+=x; sum1+=x; sum2+=x;
            maxx=max(maxx,sum1);
            if(sum1<0) sum1=0;
            minn=min(sum2,minn);
            if(sum2>0) sum2=0;
        }
        if(tsum==minn) return maxx;             // if all the elements of array are negative.
        else return max(maxx,tsum-minn);
    }
};

/***************Approach 2 Runtime 40 ms ****************
static const auto io_sync_off = [](){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     return nullptr;
}();
class Solution {
public:
    int solve(vector<int> &v){
        int csum = v[0];
        int ans= v[0];
        for(int i=1;i<v.size();i++){
            csum = max(csum+v[i],v[i]);
            ans=max(ans,csum);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& A) {
         int a1 = solve(A);
        //  cout<<a1;
        int sum = 0;
        int cnt = 0;
         for(int i=0;i<A.size();i++){
             sum+=A[i];
             if(A[i]<0)cnt++;
             A[i]=(-1)*A[i];
         }
        if(cnt==A.size()) return a1;
        int a2 = solve(A);
        return max(a1,a2+sum);
    }
};