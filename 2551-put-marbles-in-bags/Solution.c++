class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<long long > bars;
        for(int i=0;i<n-1;i++){
            bars.push_back(weights[i]+weights[i+1]);
        }
        sort(bars.begin(),bars.end());
        long long min_sum=0;
        long long max_sum=0;
        for(int i=0;i<k-1;i++){
            min_sum+=bars[i];
            max_sum+=bars[n-2-i];
        }
        return max_sum-min_sum;
        
    }
};
