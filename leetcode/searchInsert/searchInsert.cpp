//本质是一个二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            int center=(left+right)/2;
            if(nums[center]==target)
                return center;
            if(nums[center]<target)
                left=center+1;
            if(nums[center]>target)
                right=center-1;
        }
        return left;
    }
};
