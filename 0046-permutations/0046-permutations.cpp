class Solution {
public:
    void recurse(vector<vector<int>> &ans, vector<int>&temp, vector<bool>&visited, vector<int> &nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                temp.push_back(nums[i]);
                recurse(ans,temp,visited,nums);
                temp.pop_back();
                visited[i]=false;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        recurse(ans,temp,visited,nums);
        return ans;
        
    }
};