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
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        for(int i=s.size();i>=0;i--){
            for(int j=s.size();j>=0;j--){
                if(i==s.size()||j==s.size()){
                    dp[i][j]=0;
                }
                else if(s[i]==t[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
                
            }
            
            
        }
        
        return dp[0][0];
    }
};