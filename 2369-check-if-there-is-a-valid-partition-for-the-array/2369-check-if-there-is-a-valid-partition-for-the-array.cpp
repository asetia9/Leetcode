class Solution {
public:
    bool recurse(vector<int>& nums, int idx,vector<int> &dp){
        if(idx>=nums.size()){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(idx+1<nums.size()){
            if(nums[idx]==nums[idx+1]&&recurse(nums,idx+2,dp)){
               return dp[idx]=true;
            }
            if(idx+2<nums.size()){
                if((nums[idx]==nums[idx+1]&&nums[idx+1]==nums[idx+2])||(nums[idx+2]==nums[idx+1]+1&&nums[idx+1]==nums[idx]+1)){
                    if(recurse(nums,idx+3,dp)){
                        return dp[idx]=true;
                    }
                }
            }
            
        }
        return dp[idx]=false;
        
        
    }
    
    bool validPartition(vector<int>& nums){
        vector<int> dp(nums.size(),-1);
        return recurse(nums,0,dp);
        
    }
};