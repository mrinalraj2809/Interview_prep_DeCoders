/**********************************************************************
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
**********************************************************************/
// Approach 1
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        auto itr = find(nums.begin(),nums.end(),target);
        if(itr !=nums.end()){
            return itr - nums.begin();
        }
        else
        {
            return upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        }
    }
};

// Better Approach
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                l = mid + 1;
            if (nums[mid] > target)
                r = mid - 1 ;
        } 
       return l;
    }
};