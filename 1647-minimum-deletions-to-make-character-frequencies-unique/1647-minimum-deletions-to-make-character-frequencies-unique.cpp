class Solution {
public:
    int minDeletions(string s) {
        vector<int> arr(26,0);
        for(char ch:s)
            arr[ch-'a']++;
        unordered_map<int,int> m;
        for(int i=0;i<26;i++){
            if(arr[i]>0)
                m[arr[i]]++;
        }
        int ans=0;
        for(auto it:m){
            if(it.second>1){
                int extra=it.second-1;
                int less=it.first-1;
                while(extra){
                    if(m[less]==0){
                        if(less==0){
                            ans+=extra*it.first;
                            break;
                        }
                        m[less]++;
                        extra--;
                        ans+=it.first-less;
                    }
                    less--;
                }
                
                
            }
        }
        
        return ans;
        
    }
};