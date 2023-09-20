class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long sum=0;
        for(int ele:nums)
            sum+=ele;
        if(sum<x)
            return -1;
        int i=0;
        int j=0;
        long long target=sum-x;
        long long curr_sum=0;
        int maxi=-1;
        while(j<n){
            curr_sum+=nums[j];
            while(curr_sum>target){
                curr_sum-=nums[i++];
            }
            if(curr_sum==target){
                maxi=max(maxi,j-i+1);
            }
            j++;
            // cout<<curr_sum<<endl;
        }
        if(maxi==-1)
            return maxi;
        return n-maxi;
    }
};