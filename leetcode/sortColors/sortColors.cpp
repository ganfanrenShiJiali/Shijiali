//我的解法一
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int red=0;
       int white=0;
       int blue=0;
       for(int i=0;i<nums.size();i++)
       {
            if(nums[i]==0)
                red++;
            if(nums[i]==1)
                white++;
            if(nums[i]==2)
                blue++;
       }
       nums.clear();
       int i=0;
       while(i<red)
       {
           nums.push_back(0);
           i++;
       }
       i=0;
       while(i<white)
       {
           nums.push_back(1);
           i++;
       }
       i=0;
       while(i<blue)
       {
           nums.push_back(2);
           i++;
       }
    }
};
