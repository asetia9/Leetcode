class Solution {
public:
    int recurse(vector<int>& prices, int i, int status,vector<vector<int>> &dp){
        
        if(i==prices.size())
            return 0;
        if(dp[i][status]!=-1)
            return dp[i][status];
        int maxi=0;
        if(status==0){
            maxi=max(maxi,-prices[i]+recurse(prices,i+1,1,dp));
            maxi=max(maxi,recurse(prices,i+1,0,dp));
        }
        else if(status==1){
            maxi=max(maxi,prices[i]+recurse(prices,i+1,2,dp));
            maxi=max(maxi,recurse(prices,i+1,1,dp));
        }
        else{
            maxi=max(maxi,recurse(prices,i+1,0,dp));
        }
        return dp[i][status]=maxi;
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));
        return recurse(prices,0,0,dp);
    }
};