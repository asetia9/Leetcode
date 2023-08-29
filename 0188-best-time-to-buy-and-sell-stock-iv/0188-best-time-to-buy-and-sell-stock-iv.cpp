class Solution {
public:
    int recurse(vector<int>& prices, int idx, bool buy, int k,vector<vector<vector<int>>> &dp){
        if(!k){
            return 0;
        }
        if(idx==prices.size())
            return 0;
        if(dp[idx][buy][k]!=-1)
            return dp[idx][buy][k];
        int maxi=0;
        if(buy){
            maxi=max(maxi, -prices[idx]+recurse(prices,idx+1,!buy,k,dp));
            maxi=max(maxi,recurse(prices,idx+1,buy,k,dp));
        }
        else{
            maxi=max(maxi,prices[idx]+recurse(prices,idx+1,!buy,k-1,dp));
            maxi=max(maxi,recurse(prices,idx+1,buy,k,dp));
        }
        return dp[idx][buy][k]=maxi;
        
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return recurse(prices,0,true,k,dp);
    }
};