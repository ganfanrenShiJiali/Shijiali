class Solution {
public:
    bool isUnique(string astr) {
        for(int i=0; i<astr.size();i++){
            if(astr.find(astr[i])!=astr.rfind(astr[i])){//find和rfind分别是从最左和最右查询，如果位置一样，表明唯一
                return false;
            }
        }
        return true;
    }
};
