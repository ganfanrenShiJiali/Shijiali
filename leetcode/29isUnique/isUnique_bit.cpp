class Solution {
public:
    bool isUnique(string astr) {
        int mark=0;
        for(const int c:astr)
        {
            int step=c-int('a');
            if(mark & (1<<step))
                return false;
            mark|=(1<<step);
        }
        return true;
    }
};
