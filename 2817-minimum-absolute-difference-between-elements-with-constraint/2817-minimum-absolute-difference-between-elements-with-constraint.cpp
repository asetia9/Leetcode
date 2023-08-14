class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int mini=INT_MAX;
        for(int i=x;i<nums.size();i++){
            s.insert(nums[i-x]);
            auto it = s.upper_bound(nums[i]);
            if(it!=s.end()){
            mini=min(mini,*it-nums[i]);
            }
            if(it!=s.begin()){
            mini=min(mini,nums[i]-*prev(it));
            }
        }
        return mini;
    }
};