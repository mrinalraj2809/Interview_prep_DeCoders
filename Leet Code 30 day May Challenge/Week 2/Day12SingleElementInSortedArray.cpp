You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10


```cpp
//Approach 1: Map Runtime 36ms
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        map<int,int> m;m.insert(pair<int,int>(nums[0],1));
        for(int i=1;i<nums.size();i++)
        {
            auto it = m.find(nums[i]);
            if(it != m.end())
            {
                it->second += 1;
            }
            else
                m.insert(pair<int,int>(nums[i],1));
        }
        // for(int i=0;i<m.size();i++)
        for(auto it = m.begin(); it != m.end();it++)
        {
            if(it->second == 1)return it->first;
        }
        return 0;
    }
};

//Approach 2: Binary search approach Runtime 12 ms
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if (nums.size() % 2 == 0)
            return -1;
        
        int low = 0;
        int high = nums.size()-1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            bool half_even = (high - mid) % 2 == 0;
            if (nums[mid+1] == nums[mid]) {
                if (half_even) {
                    low = mid + 2;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid-1] == nums[mid]) {
                if (half_even) {
                    high = mid - 2;
                } else {
                    low = mid + 1; 
                }
            } else {
                return nums[mid];
            }
            
        }
        return nums[low];
    }
};

//Approach 3: Efficient code Runtime 0 ms
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
	    // Since element appear exactly twice so XOR opration cancels itself.
            x = x^nums[i];
        }
        return x;
    }
};