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
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                
                for(int l=1;l<=k;l++){
                    int maxi=0;
                    if(j){
                        maxi=max(maxi,-prices[i]+dp[i+1][0][l]);
                        maxi=max(maxi,dp[i+1][1][l]);
                    }
                    else{
                        maxi=max(maxi,prices[i]+dp[i+1][1][l-1]);
                        maxi=max(maxi,dp[i+1][0][l]);
                    }
                    
                    
                   dp[i][j][l]=maxi; 
                    
                }
                
                
                
            }
            
            
            
        }
        
        
        return dp[0][1][k];
    }
};