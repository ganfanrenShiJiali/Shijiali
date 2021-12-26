class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        if(len==0) return 0;
        int fast,slow=0;
        for(fast=0;fast<len;fast++)
        {
            if(nums[fast]!=val)
            {
                nums[slow]=nums[fast];
                slow++;
            };
        }
        return slow;
    }
};
