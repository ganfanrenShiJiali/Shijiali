//我的解法
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>pairs={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int i;
        int num=0;
        for(i=0;i<s.size();)
        {
            if(pairs[s[i]] >= pairs[s[i+1]])
            {
                num+=pairs[s[i]];
                i++;
            }
            else
            {
                num+=(pairs[s[i+1]]-pairs[s[i]]);
                i=i+2;
            }
        }
        return num;
    }
};
