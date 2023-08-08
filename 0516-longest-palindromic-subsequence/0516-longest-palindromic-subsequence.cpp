class Solution {
public:
    int lcs(string& s, string &t, int i,int j,vector<vector<int>> &dp){
        if(i==s.size()||j==t.size())
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]= 1+lcs(s,t,i+1,j+1,dp);
        }
        return dp[i][j]=max(lcs(s,t,i+1,j,dp),lcs(s,t,i,j+1,dp));
        
    }
    int longestPalindromeSubseq(string s) {
        string t="";
        
        for(int i=s.size()-1;i>=0;i--){
            t+=s[i];
        }
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return lcs(s,t,0,0,dp);
    }
};