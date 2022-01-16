class Solution {
public:
    vector<vector<int>> towSum(vector<int>& nums,int left,int right,int target,int value1,int value2)
    {
        vector<vector<int>>res;
        while(left<right)
        {
            vector<int>set;
            if(nums[left]+nums[right]==target)
            {
                set.push_back(nums[left]);
                set.push_back(nums[right]);
                set.push_back(value1);
                set.push_back(value2);
                res.push_back(set);
                set.clear();
                while(left<right && nums[left+1]==nums[left])
                    left++;
                left++;
                while(left<right && nums[right-1]==nums[right])
                    right--;
                right--;
            }
            else if(nums[left]+nums[right]<target)
                left++;
            else
                right--;
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len=nums.size();
        if(len<4) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<len-2;j++)
            {
                if(j-1>i && nums[j]==nums[j-1])
                    continue;
                auto result=towSum(nums,j+1,len-1,target-nums[i]-nums[j],nums[i],nums[j]);
                ans.insert(ans.end(),result.begin(),result.end());
            }
        }
        return ans;
    }
};
