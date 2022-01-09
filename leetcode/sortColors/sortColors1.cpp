//双指针法
class Solution {
public:
    void swap(vector<int>& nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) 
    {
        int len=nums.size();
        if(len<2)
            return;
        int p0=0,i=0;
        int p2=len-1;
        while(i<=p2)
        {
            if(nums[i]==0)
            {
                swap(nums,i,p0);
                p0++;
                i++;
            }
            else if(nums[i]==1)
                i++;
            else
            {
                swap(nums,i,p2);
                p2--;
            }
        }
    }
};
