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
        vector<vector<int>> dp(prices.size()+1,vector<int>(3,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=2;j++){
                int maxi=0;
                if(j==0){
                    maxi=max(maxi,-prices[i]+dp[i+1][1]);
                    maxi=max(maxi,dp[i+1][0]);
                }
                else if(j==1){
                    maxi=max(maxi,prices[i]+dp[i+1][2]);
                    maxi=max(maxi,dp[i+1][1]);
                }
                else
                    maxi=max(maxi,dp[i+1][0]);
                dp[i][j]=maxi;
                
            }
            
            
        }
        return dp[0][0];
    }
};