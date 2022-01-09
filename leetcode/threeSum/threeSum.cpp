//我的解法：一顿操作猛如虎，击败用户百分五
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<=2) return result;
        unordered_map<int,int>number;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            number[nums[i]]=i;
        }
        vector<int> set;
        map<vector<int>,int>acao;
        for(int j=0;j<nums.size();j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                if(number.find(-(nums[j]+nums[k]))!=number.end() && number[-(nums[j]+nums[k])]>k)
                {
                    int r=number[-(nums[j]+nums[k])];
                    set.push_back(nums[j]);
                    set.push_back(nums[k]);
                    set.push_back(nums[r]);
                    if(acao.find(set)==acao.end())
                    {
                        acao[set]=1;
                        result.push_back(set);
                    }
                    set.clear();
                }
            }
        }
        return result;
    }
};
  
//双指针法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=2) return ans;
        sort(nums.begin(),nums.end());//排序，避免重复解
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            auto result=towSum(nums,i+1,nums.size()-1,-nums[i],nums[i]);
            ans.insert(ans.end(),result.begin(),result.end());
        }
        return ans;
    }
    vector<vector<int>> towSum(vector<int>&nums,int start,int end,int target,int value)
    {
        vector<vector<int>> result;
        while(start<end)
        {
            if(nums[start]+nums[end]==target)
            {
                vector<int>set;
                set.push_back(nums[start]);
                set.push_back(nums[end]);
                set.push_back(value);
                result.push_back(set);
                set.clear();
                while(start<end && nums[start]==nums[start+1])
                    start++;
                start++;
                while(start<end && nums[end]==nums[end-1])
                    end--;
                end--;
            }
            else if(nums[start]+nums[end]<target)
                start++;
            else
                end--;
        }
        return result;
    }
};
