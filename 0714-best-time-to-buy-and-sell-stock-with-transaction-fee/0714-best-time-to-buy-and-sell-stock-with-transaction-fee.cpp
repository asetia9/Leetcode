class Solution {
public:
    int recurse(vector<int>& prices, int i, int fee, bool buy,vector<vector<int>> &dp){
        if(i==prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int maxi=0;
        if(buy){
            maxi=max(maxi,-prices[i]+recurse(prices,i+1,fee,0,dp));
            maxi=max(maxi,recurse(prices,i+1,fee,1,dp));
        }
        else{
            maxi=max(maxi,prices[i]+recurse(prices,i+1,fee,1,dp)-fee);
            maxi=max(maxi,recurse(prices,i+1,fee,0,dp));
        }
        return dp[i][buy]=maxi;
        
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return recurse(prices,0,fee,true,dp);
    }
};