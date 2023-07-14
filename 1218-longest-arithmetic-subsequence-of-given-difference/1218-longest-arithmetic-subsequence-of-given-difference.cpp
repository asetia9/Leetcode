class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        int maxi=1;
        for(int ele:arr){
            if(m[ele-difference]!=0){
                m[ele] = 1+ m[ele-difference];
            }
            else
                m[ele]=1;
            maxi=max(maxi,m[ele]);
        }
        return maxi;
    }
};