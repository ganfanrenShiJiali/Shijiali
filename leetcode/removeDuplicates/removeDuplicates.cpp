class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len==0||len==1) return len;
        int i=1,j;
        for(j=1;j<nums.size();j++)
        {
            if(nums[j]!=nums[i-1])
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};
