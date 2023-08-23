class Solution {
public:
    class comparator{
        public:
        bool operator()(pair<char,int> a, pair<char,int> b){
            return a.second<b.second;
        }
        
    };
    string reorganizeString(string s) {
         
        unordered_map<char,int> m;
        for(char ch:s)
            m[ch]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>, comparator> pq;
        for(auto it:m){
            pq.push({it.first,it.second});
        }
        string ans="";
        while(true){
            bool flag=true;
            if(ans.size()==s.size())
                break;
            

                if(!ans.size()){
                    ans+=pq.top().first;
                    pair<char,int> rm = pq.top();
                    pq.pop();
                    rm.second-=1;
                    pq.push(rm);
                    flag=false;
                }
                else{
                    if(ans[ans.size()-1]!=pq.top().first&&pq.top().second>0){
                        ans+=pq.top().first;
                        pair<char,int> rm = pq.top();
                        pq.pop();
                        rm.second-=1;
                        pq.push(rm);
                        flag=false;
                    }
                    else{
                        pair<char,int> rm=pq.top();
                        pq.pop();
                        if(pq.size()&&pq.top().second>0){
                            ans+=pq.top().first;
                            pair<char,int> rm = pq.top();
                            pq.pop();
                            rm.second-=1;
                            pq.push(rm);
                            flag=false;
                        }
                        pq.push(rm);
                    }
                
            }
            if(flag)
                break;
        }
        return ans.size()==s.size()?ans:"";
    }
};