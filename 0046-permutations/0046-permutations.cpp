class Solution {
public:
    void recurse(vector<vector<int>> &ans, vector<int>&temp, vector<bool>&visited, vector<int> &nums, int n){
        if(!n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                temp.push_back(nums[i]);
                recurse(ans,temp,visited,nums,n-1);
                temp.pop_back();
                visited[i]=false;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        int n = nums.size();
        recurse(ans,temp,visited,nums,n);
        return ans;
        
    }
};