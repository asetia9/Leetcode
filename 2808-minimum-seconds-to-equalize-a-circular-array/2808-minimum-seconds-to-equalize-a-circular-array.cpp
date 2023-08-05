class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto &[n, v]: m){
            v.push_back(v[0]+nums.size());
            int maxi=0;
            for(int i=1;i<v.size();i++){
                maxi=max((v[i]-v[i-1])/2,maxi);
            }
            mini = min(mini,maxi);
            
        }
        return mini;
        
    }
};