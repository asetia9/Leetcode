class Solution {
public:
    int minChars(string &s, int idx, unordered_map<string,int> &m,vector<int> &dp){
        if(idx==s.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans = 1+minChars(s,idx+1,m,dp);
        string temp="";
        for(int i=idx;i<s.size();i++){
            temp+=s[i];
            if(m.find(temp)!=m.end()){
                ans = min(ans,minChars(s,i+1,m,dp));
            }
        }
        return dp[idx]=ans;
        
        
    }
    
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> m;
        for(string str:dictionary)
            m[str]++;
        vector<int> dp(s.size(),-1);
        return minChars(s,0,m,dp);
    }
};