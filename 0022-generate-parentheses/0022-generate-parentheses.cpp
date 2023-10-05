class Solution {
public:
    vector<string> recurse(int open, int close){
        if(open==0){
            string str="";
            while(close-->0)
                str+=')';
            return {str};
        }
        if(close==0){
            return {};
        }
            vector<string> ans;
            if(close>open){
                vector<string> next = recurse(open,close-1);
                for(auto s:next){
                    ans.push_back(")"+s);
                }
            }
            if(open>0){
            vector<string> next = recurse(open-1,close);
            for(auto s:next)
                ans.push_back("("+s);
            }
        return ans;
              
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        return recurse(n,n);
    }
};