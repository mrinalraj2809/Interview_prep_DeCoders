int main(){
    vector<int> res;int k=0;
    vector<int> twoSum(vector<int>& nums, int target){
           if(target == 0 || k==nums.size())return res;
           if(target - nums[k] >= 0)
           {
               res.push_back(k);
               target = target - nums[i];k++;
               return twoSum(nums,target);
           }
           k++;
       }
        return res;
    }
    int n,target;
      
	cout<<twoSum
}
