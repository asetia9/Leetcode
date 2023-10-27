class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> v(26,{-1,-1});
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(v[ch-'a'].first==-1){
                v[ch-'a'].first=i;
                v[ch-'a'].second=i;
            }
            else{
                v[ch-'a'].second=i;
            }
        }
        sort(v.begin(),v.end());
        int i=0;
        while(i<26&&v[i].first==-1)
            i++;
        vector<pair<int,int>> parr;
        parr.push_back(v[i++]);
        while(i<26){
            int sz=parr.size();
            if(v[i].first<parr[sz-1].second){
                parr[sz-1].second=max(parr[sz-1].second,v[i].second);
            }
            else{
                parr.push_back(v[i]);
            }
            i++;
        }
        vector<int> ans;
        for(auto p:parr){
            ans.push_back(p.second-p.first+1);
        }
        return ans;
        
    }
};