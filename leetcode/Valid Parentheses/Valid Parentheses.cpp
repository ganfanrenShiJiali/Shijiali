class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n%2==1)
            return false;
        unordered_map<char,char>pairs={
            {')','('},
            {'}','{'},
            {']','['}
        };//哈希表定义，先key后value
        stack<char>stk;//栈定义
        for(char ch:s)//相当于遍历字符串，每次遍历的元素存在ch中
        {
            if(pairs.count(ch))//检查是否在哈希表中
            {
                if(stk.empty() || stk.top()!=pairs[ch])
                    return false;
                stk.pop();
            }
            else
                stk.push(ch);
        }
        return stk.empty();
    }
};
-----------------------------------------------------------------------------------------------------
class Solution 
{
public:
    bool isValid(string s) 
    {
        int n=s.size();
        if(n%2==1)
            return false;
        stack<char>stk;
        for(char ch:s)
        {
            if(stk.empty()&&ch==')' || stk.empty()&&ch=='}' || stk.empty()&&ch==']' )
                return false;
            if(ch=='(' || ch=='{' || ch=='[')
                stk.push(ch);
            else
            {
        if(stk.top()=='('&&ch==')'||stk.top()=='{'&&ch=='}'||stk.top()=='['&&ch==']')
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
