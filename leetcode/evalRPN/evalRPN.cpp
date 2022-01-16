class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string>characters={"+","-","*","/"};
        stack<int>num;
        for(int i=0;i<tokens.size();i++)
        {
            if(characters.count(tokens[i]))
            //if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int n2=num.top();
                num.pop();
                int n1=num.top();
                num.pop();
                int res;
                if(tokens[i]=="+")
                    res=n1+n2;
                else if(tokens[i]=="-")
                    res=n1-n2;
                else if(tokens[i]=="*")
                    res=n1*n2;
                else
                    res=n1/n2;
                num.push(res);
            }
            else
                num.push(stoi(tokens[i]));
        }
        return num.top();
    }      
};
