class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        unordered_map<char,int> m;
        for(char ch: s){m[ch]++;}
        for(pair<char,int> p1:m){
            for(auto p2:m){
                
                char ch1=p1.first;
                char ch2=p2.first;
                if(ch1==ch2){continue;}
                int rev=2;
                while(rev--){
                    int cnt1=0;
                    int cnt2=0;
                    for(char ch:s){
                        if(ch==ch1){cnt1++;}
                        if(ch==ch2){cnt2++;}
                        if(cnt1<cnt2){cnt1=cnt2=0;}
                        if(cnt1&&cnt2){
                            ans=max(ans,cnt1-cnt2);
                        }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};