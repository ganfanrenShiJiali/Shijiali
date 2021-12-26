//修改我的解法：滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        unordered_map<char,int>pairs;
        int maxlen=0;
        int nowmaxlen=0;
        int pos=0;
        int i;
        for(i=0;i<s.size();i++)
        {
            if(pairs.find(s[i])==pairs.end())
            {
                pairs[s[i]]=i;
                nowmaxlen++;
            }
            else
            {
                if(nowmaxlen>maxlen)
                {
                    maxlen=nowmaxlen;
                }  
                pos=max(pairs[s[i]],pos);
                nowmaxlen=i-pos;
                pairs[s[i]]=i;
            }
        }
        if(nowmaxlen>maxlen) 
        {
            maxlen=nowmaxlen;
        }
        return maxlen;
    }
};
