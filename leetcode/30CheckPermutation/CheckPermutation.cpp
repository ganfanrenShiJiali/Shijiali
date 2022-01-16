//我的解法
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int len1=s1.size();
        int len2=s2.size();
        if(len1!=len2) return false;
        unordered_map<char,int>letters;
        for(int i=0;i<len1;i++)
        {
            if(letters.find(s1[i])==letters.end())
                letters[s1[i]]=1;
            else
                letters[s1[i]]++;
        } 
        for(int j=0;j<len2;j++)
        {
            if(letters.find(s2[j])==letters.end())
                return false;
            else
                letters[s2[j]]--;
        }
        int i=0;
        for(auto &it:letters)//注意哈希表的遍历
        {
            if(it.second!=0)
                return false;
        }
        return true;
    }
};
