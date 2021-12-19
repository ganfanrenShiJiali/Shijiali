//我的解法，纵向扫描
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre="";
        int i,j;
        for(j=0;j!=strs[0].size();j++)
        {
            char s=strs[0][j];
            for(i=1;i<strs.size();i++)
            {
                if(strs[i][j]!=s)
                    break;
            }
            if(i==strs.size())
                pre=pre+s;
            else
                break;
        }
        return pre;
    }
};

//同样的方法可以稍微改进，占用内存更少
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        int i,j;
        int length=strs[0].size();
        int size=strs.size();
        for(j=0;j!=length;j++)
        {
            char s=strs[0][j];
            for(i=1;i<size;i++)
            {
                if(strs[i][j]!=s)
                    return strs[0].substr(0,j);
            }
        }
        return strs[0];
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string prefix = strs[0];//取第一个字符串初始化公共字符串
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) {//一旦公共字符串为空，立马停止循环
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index;
        }
        return str1.substr(0, index);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        else {
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }
    }

    string longestCommonPrefix(const vector<string>& strs, int start, int end) {
        if (start == end) {
            return strs[start];
        }
        else {
            int mid = (start + end) / 2;
            string lcpLeft = longestCommonPrefix(strs, start, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, end);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(const string& lcpLeft, const string& lcpRight) {
        int minLength = min(lcpLeft.size(), lcpRight.size());
        for (int i = 0; i < minLength; ++i) {
            if (lcpLeft[i] != lcpRight[i]) {
                return lcpLeft.substr(0, i);
            }
        }
        return lcpLeft.substr(0, minLength);
    }
};
