//袖珍计算器
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int ans=exp(0.5*log(x));
        return ((long long)(ans+1)*(ans+1)<=x?ans+1:ans);
    }
};

//二分查找
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int left=0,right=x;
        while(left<=right)
        {
            long mid=(left+right)/2;//长整型,否则mid平方会越界
            if(mid*mid==x)
                return mid;
            if(mid*mid<x)
                left=mid+1;
            else
                right=mid-1;
        }
        return right;
    }
};

//牛顿迭代
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        double a0=x,C=x;//注意是double类型，在32位下不会出现因精度问题影响结果的情况
        while(true)
        {
            double ai=0.5*(a0+C/a0);
            if(fabs(a0-ai)<1e-7)//1e-7或者1e-6都可以，两者之差小于某个极小值
                break;
            a0=ai;
        }
        return int(a0);//返回为整数
    }
};
