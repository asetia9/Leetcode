class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum=0;
        m[0]=1;
        int ans=0;
        for(int ele:nums){
            sum+=ele;
            int rem = sum%k;
            if(rem<0)
                rem+=k;
            if(m.find(rem)!=m.end())
                ans+=m[rem];
            m[rem]++;
            
        }
        return ans;
        
        
    }
};