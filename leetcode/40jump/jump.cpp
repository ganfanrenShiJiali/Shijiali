//我的解法
class Solution {
public:
    int jump(vector<int>& nums) {
        int len=nums.size();
        if(len==1) return 0;
        vector<int>steps(len,INT_MAX);
        steps[0]=0;
        for(int i=0;i<len-1;i++)
        {
            int cover=i+nums[i];
            for(int j=i+1;j<=cover;j++)
            {
                int cur=steps[i]+1;
                steps[j]=min(steps[j],cur);
                if(j==len-1) break;
            }
        }
        return steps[len-1];
    }
};
