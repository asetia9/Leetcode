class Solution {
public:
    bool leadsToTerminal(int idx, vector<vector<int>>& graph,vector<bool> &visited,vector<int> &dp){
        if(dp[idx]!=-1){
            return dp[idx];
        }
    
        if(visited[idx]){
            return dp[idx] = false;
        }
        visited[idx]=true;
        for(int ele:graph[idx]){
            if(!leadsToTerminal(ele,graph,visited,dp)){
                return dp[idx]=false;
            }
        }
        return dp[idx]=true;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> dp(n,-1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            if(leadsToTerminal(i,graph,visited,dp)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};