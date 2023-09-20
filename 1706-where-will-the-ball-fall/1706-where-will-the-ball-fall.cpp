class Solution {
public:
    int recurse(int i, int j, vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(dp[i][j]!=-2)
            return dp[i][j];
        if(i==grid.size())
            return dp[i][j]=j;
        if(grid[i][j]==1){
            if(j==grid[0].size()-1 || grid[i][j+1]==-1)
                return dp[i][j]=-1;
            return dp[i][j]=recurse(i+1,j+1,grid,dp);
        }
        if(j==0 || grid[i][j-1]==1)
            return dp[i][j]=-1;
        return dp[i][j]=recurse(i+1,j-1,grid,dp);
    }
    
    
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size(),-2));
        for(int i=0;i<grid[0].size();i++){
            int a = recurse(0,i,grid,dp);
            ans.push_back(a);
        }
        return ans;
    }
};