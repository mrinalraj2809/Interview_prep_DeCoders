#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> twoSum(vector<int>& nums, int target){
       static vector<int> res;static int k=0;
      for(int i=k;i<nums.size();i++){
         if(target == 0 || k==nums.size()-1)return res;
         if(target - nums[k] >= 0)
         {
             res.push_back(k);
             target = target - nums[i];k++;
             return twoSum(nums,target);
         }
          res.pop_back();
         k++;
     }
      cout<<res;
      return 0;
  }
}
