class Solution {
public:
    vector<string> getCombinations(string &digits, int idx, unordered_map<int,string>&m){
        
        if(idx==digits.size()-1){
            
            vector<string> ans;
            for(char ch:m[digits[idx]-'0']){
                string temp="";
                temp+=ch;
                ans.push_back(temp);
            }
            return ans;
            
        }
        vector<string> next = getCombinations(digits, idx+1, m);
        vector<string> ans;
        for(char ch:m[digits[idx]-'0']){
            string tbp="";
            tbp+=ch;
   
            for(string s:next){
                tbp+=s;
                ans.push_back(tbp);
                tbp="";
                tbp+=ch;
            }
            
            
        }
        return ans;
        
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
         unordered_map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        return getCombinations(digits,0,m);
            
    }
};