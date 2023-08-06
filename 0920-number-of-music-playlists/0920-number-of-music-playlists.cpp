class Solution {
public:
    int MOD=1e9+7;
    long long recurse(int n, int goal, int idx, int k, vector<int> &visited, vector<vector<long long>> &dp){
        
        long long uniq = 0;
        for(int i=0;i<n;i++){
            if(visited[i]!=-1){
                uniq++;
            }
        }
        if(idx==goal){
            return uniq==n;
        }
     
        
        if(dp[idx][uniq]!=-1){
            return dp[idx][uniq];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
           
            if(idx>visited[i]){
                int prev=visited[i];
                visited[i]=idx+k;
                ans=(ans+recurse(n,goal,idx+1,k,visited,dp))%MOD;
                visited[i]=prev;
            }
            
            
        }
        
        return dp[idx][uniq]=ans%MOD;
        
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<int> visited(n, -1);
        vector<vector<long long>> dp(goal+1,vector<long long>(n+1,-1));
        return recurse(n,goal,0,k,visited,dp);
    }
};