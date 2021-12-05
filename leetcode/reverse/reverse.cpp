//我的解法（报错）
int reverse(int x)
{
	long n = 0;
    if(x==0) return 0;
    else
    {
        if(x>0)
        {
            while(x!=0)
            {
                n = n * 10 + x % 10;
		        x /= 10;
            }
        }
        else
        {
            x=-x;
            while(x!=0)
            {
                n = n * 10 - x % 10;
		        x /= 10;
            }
        }
    }
	return n > INT_MAX || n < INT_MIN ? 0 : n;
}
//改进算法
int reverse(int x)
{
	long n = 0;
	while(x)
	{
		n = n * 10 + x % 10;
		x /= 10;
	}
	return n > INT_MAX || n < INT_MIN ? 0 : n;
}
