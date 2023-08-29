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
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int maxi=0;
                if(j){
                    maxi=max(maxi,-prices[i]+dp[i+1][0]);
                    maxi=max(maxi,dp[i+1][1]);
                }
                else{
                    maxi=max(maxi,prices[i]+dp[i+1][1]-fee);
                    maxi=max(maxi,dp[i+1][0]);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[0][1];
    }
};