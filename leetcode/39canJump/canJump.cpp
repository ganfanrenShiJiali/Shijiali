class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return true;
        int cover=0;
        for(int i=0;i<=cover && cover<len-1;i++)
        {
            cover=max(i+nums[i],cover);
        }
        return cover>=len-1;
    }
};
