class Solution {
public:
    int recurse(vector<vector<int>>& offers, int idx, vector<int> &dp){
        if(idx==offers.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int low=idx+1;
        int high=offers.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(offers[mid][0]>offers[idx][1]){
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }
        int maxi=offers[idx][2];
        if(ans!=-1)
            maxi+= recurse(offers,ans,dp);
        maxi=max(maxi,recurse(offers,idx+1,dp));
        return dp[idx]=maxi;
        
        
    }
    
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        vector<int> dp(offers.size(),-1);
        return recurse(offers,0,dp);
    }
};