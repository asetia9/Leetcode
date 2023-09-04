class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long count=0;
        for(int &ele:nums){
            if(ele%modulo==k)
                ele=1;
            else
                ele=0;
        }
        unordered_map<int,int> m;
        int sum=0;
        for(int ele:nums){
            sum+=ele;
            int remainder = sum%modulo;
            if(remainder==k) count++;
            int find = remainder-k;
            if(find<0)
                find+=modulo;
            count+=m[find];
            m[remainder]++;
        }
        return count;
    }
};