//我的解法
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sum=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
                sum++;
            if(sum!=0 && s[i]==' ')
                break;
        }
        return sum;
    }
};
