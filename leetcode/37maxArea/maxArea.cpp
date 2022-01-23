class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        //if(len==1 || len ==0) return 0;
        //if(len==2) return min(height[0],height[1]);
        int volume=0;
        int cur;
        int left=0;
        int right=len-1;
        while(left<right)
        {
            int minn=min(height[left],height[right]);
            cur=minn*(right-left);
            if(height[left]<=height[right])
                left++;
            else if(height[left]>height[right])
                right--;
            //if(cur>volume)
                //volume=cur;
            volume=max(cur,volume);
        }
        return volume;
    }
};
