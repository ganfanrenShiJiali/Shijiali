class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        if(len<3) return 0;
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        int sum;
        for(int i=0;i<len;i++)
        {
            int left=i+1;
            int right=len-1;
            while(left<right)
            {
                sum=nums[i]+nums[left]+nums[right];
                if(sum==target)
                    return target;
                else if(sum<target)
                    left++;
                else
                    right--;
                if(abs(target-sum)<abs(target-ans))
                    ans=sum;
            }
        }
        return ans;
    }
};
