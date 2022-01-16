//我写的暴力解法
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1) return s;
        int left = 0;
        int right = len - 1;
        bool flag = false;
        int ii = 0, jj = 0;
        int maxLen = 1;
        int maxLeft = 0;
        for (int i = left; i < len - 1; i++)
        {
            for (int j = len - 1; j > i; j--)
            {
                if (s[i] == s[j])
                {
                    ii = i;
                    jj = j;
                    flag = true;
                    while (++i < --j)
                    {
                        if (s[i] != s[j])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true)
                    {
                        i = ii;
                        break;
                    }
                    else
                    {
                        i = ii;
                        j = jj;
                    }
                }
            }
            if (flag == true && (jj - ii + 1) > maxLen)
            {
                maxLen = jj - ii + 1;
                maxLeft = ii;
                flag = false;
            }
        }
        string res = s.substr(maxLeft, maxLen);
        return res;
    }
};
