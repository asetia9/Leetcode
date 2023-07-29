class Solution {
public:
    double helper(int a, int b, vector<vector<double>> &dp){
        if(a<=0&&b<=0){
            return 0.5;
        }
        if(a<=0){
            return 1.0;
        }
        if(b<=0){
            return 0.0;
        }
        if(dp[a][b]!=-1.0)
            return dp[a][b];
        dp[a][b]=0.0;
        dp[a][b]+=helper(a-100,b,dp);
        dp[a][b]+=helper(a-75,b-25,dp);
        dp[a][b]+=helper(a-50,b-50,dp);
        dp[a][b]+=helper(a-25,b-75,dp);
        dp[a][b]*=0.25;
        return dp[a][b];
    }
    
    
    double soupServings(int n) {
        if(n>4300)
            return 1.0;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1.0));
        return helper(n,n,dp);    
    }
};