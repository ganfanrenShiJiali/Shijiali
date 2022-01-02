//我的解法
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        int i=len-1;
        if(digits[i]!=9)
        {
            digits[i]++;
            return digits;
        }
        while(i>=0 && digits[i]==9)
        {
            digits[i]=0;
            i--;
        }
        if(i==-1)
            digits.insert(digits.begin(),1);
        else
            digits[i]++;
        return digits;
    }
};

//取余判断加一后是否为0
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1;i>=0;i--)
        {
            digits[i]=(digits[i]+1)%10;
            if(digits[i]!=0)
                return digits;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};
