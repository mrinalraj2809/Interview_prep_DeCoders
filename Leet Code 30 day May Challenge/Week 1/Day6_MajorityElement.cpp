/***********************************************
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
************************************************/


/************** Solution cpp *******************/
/*******Brute force ***********/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<int,int> m;m.insert(pair<int,int>(nums[0],1));
        for(int i=1;i<nums.size();i++)
        {
            auto itr = m.find(nums[i]) ;
            if(itr != m.end())
            {
                itr->second = itr-> second +1;
            }
            else
                m.insert(pair<int,int>(nums[i],1));
        }
        for(auto itr = m.begin(); itr != m.end(); itr++)
        {
            if(itr->second > nums.size() / 2)
                return itr->first;
        }
        return 0;
    }
};


/* effecient approch */
// //method 1:  hashmap
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int> dict;
//         for(auto& num : nums) dict[num]++;
//         for(auto& x : dict){
//             if(n < 2 * x.second)  return x.first;
//         }
//         return 0;
//     }
// };



// //method 2:  sort
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size()/2];
//     }
// };



// method 3: 某个数字出现的次数大于数组长度的一半，意思就是它出现的次数比其他所有数字出现的次数和还要多。
// 如果每次除去出现次数最大的元素的个数与其他数字的个数相等，规律依然存在
class Solution {
public:
    Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        for(auto& num : nums){
            if(count == 0){
                ans = num; count = 1;
            }else{
                count += (ans == num) ? 1 : -1;
            }
        }
        return ans; //You may assume that the array is non-empty and the majority element always exist in the array.
    }
};
