class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool> ans;
        unordered_map<int,vector<int>> graph;
        for(auto p:pre){
            graph[p[0]].push_back(p[1]);
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            vector<bool> visited(n,false);
            while(q.size()){
                int rm = q.front();
                q.pop();
                visited[rm]=true;
                for(int ele:graph[rm]){
                    dp[i][ele]=true;
                    if(!visited[ele])
                        q.push(ele);
                    
                }
            }
        }
        for(auto q:queries){
            ans.push_back(dp[q[0]][q[1]]);
        }
        
        return ans;
    }
};