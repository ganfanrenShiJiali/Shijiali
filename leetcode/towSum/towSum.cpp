//暴力求解
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int>result;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }   
            }
        }
        return result;
    }
};
//一遍哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int len=nums.size();
      unordered_map<int,int>hashtable;
      hashtable[nums[0]]=0;
      int i;
      for(i=1;i<len;i++)
      {
          if(hashtable.find(target-nums[i])!=hashtable.end())
          {
              int index=hashtable[target-nums[i]];
              return {i,index};
          }
          else
            hashtable[nums[i]]=i;
      }
      return {};
    }
};
