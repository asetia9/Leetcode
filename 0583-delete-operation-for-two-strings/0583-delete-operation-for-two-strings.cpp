class Solution {
public:
    int minDistance(string s, string t) {
    
        int m=s.size();
        int n=t.size();
       
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==s.size()||j==n){
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
        
        return m+n-2*dp[0][0];
    }
};