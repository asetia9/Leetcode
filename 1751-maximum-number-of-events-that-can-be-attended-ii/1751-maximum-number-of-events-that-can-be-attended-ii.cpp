class Solution {
public:
    int recurse(int idx, vector<vector<int>>& events, int k,vector<vector<int>>&dp){
        
        if(k==0||idx>=events.size()){
            return 0;
        }
       if(dp[idx][k]!=-1)
           return dp[idx][k];
       int new_idx;
        for(new_idx=idx+1;new_idx<events.size();new_idx++){
            if(events[new_idx][0]>events[idx][1])
                break;
        }
        
        int take = events[idx][2]+recurse(new_idx, events, k-1,dp);
        int nonTake = recurse(idx+1,events,k,dp);
        return dp[idx][k]=max(take,nonTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return recurse(0,events,k,dp);
    }
};