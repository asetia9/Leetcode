class Solution {
public:
    
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.rbegin(), batteries.rend());
        long long sum=0;
        for(int ele:batteries)
            sum+=ele;
        for(int i=0;i<batteries.size();i++,n--){
            if(batteries[i]<=sum/n)
                break;
                sum-=batteries[i];
            
        }
            return sum/n;
    }
};