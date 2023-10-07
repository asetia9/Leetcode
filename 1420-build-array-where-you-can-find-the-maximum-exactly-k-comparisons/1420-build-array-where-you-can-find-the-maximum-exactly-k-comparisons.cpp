class Solution {
public:
    int MOD = 1e9+7;
    int recurse(int idx, int k, int n, int m, int prev,vector<vector<vector<int>>> &dp){
        if(idx==n&&k==0){
            // cout<<prev<<" "<<k<<endl;
            return 1;
        }
        if(idx==n){
            return 0;
        }
        if(dp[idx][prev+1][k]!=-1)
            return dp[idx][prev+1][k];
        int sum = 0;
        for(int i=1;i<=m;i++){
            if(i>prev){
                if(k-1>=0)
                    sum=(sum+recurse(idx+1,k-1,n,m,i,dp))%MOD;
            }
            else{
                sum=(sum+recurse(idx+1,k,n,m,prev,dp))%MOD;
            }
        }
        return  dp[idx][prev+1][k] = sum%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+2,vector<int>(k+1,-1)));
        return recurse(0,k,n,m,-1,dp);
    }
};