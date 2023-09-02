class Solution {
public:
    int recurse(vector<int>& nums, int idx,int prev,vector<vector<int>> &dp){
        if(idx==nums.size()) return 0;
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        dp[idx][prev+1] = recurse(nums,idx+1,prev,dp);
        if(prev==-1 || nums[idx]>nums[prev]){
             dp[idx][prev+1]=max(1+recurse(nums,idx+1,idx,dp),dp[idx][prev+1]);
        }
        return dp[idx][prev+1];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        vector<int> next(nums.size()+1,0);
        vector<int> curr(nums.size()+1,0);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>=-1;j--){
                curr[j+1]=next[j+1];
                if(j==-1||nums[i]>nums[j])
                    curr[j+1]=max(curr[j+1],1+next[i+1]);
                
            }
            next=curr;
        }
        
        
        return curr[0];
    }
};