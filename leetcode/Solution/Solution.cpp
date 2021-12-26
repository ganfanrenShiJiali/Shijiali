class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)) return false;//如果最后一位为0，false，因为最高位不可能为0
        int reverse=0;
        while(x>reverse)
        {
            reverse=reverse*10+x%10;
            x/=10;
        }
        return x==reverse/10 || x==reverse;
        //偶数：x==reverse
        //奇数：x==reverse/10 通过reverse去除中间的数字，中间的数字总和自己相等，不影响结果
    }
};
