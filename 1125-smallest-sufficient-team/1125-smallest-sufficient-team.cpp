class Solution {
public:
    vector<int> gg;
    void recurse(vector<int> &masks, int cmask, int idx,vector<int> &ans,vector<bool> &banned,int &n){
        if(idx==masks.size()){
            if(cmask==((1<<n)-1)){
                if(gg.size()==0||gg.size()>ans.size())
                    gg=ans;
            }
            return;
        }
        recurse(masks,cmask,idx+1,ans,banned,n);
        if(!banned[idx]){
        ans.push_back(idx);
        recurse(masks,cmask | masks[idx],idx+1,ans,banned,n);
        ans.pop_back(); 
        }
    }
    
    
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        unordered_map<string,int> m;
        for(int i=0;i<req_skills.size();i++){
            m[req_skills[i]]=i;
        }
        vector<int> masks(people.size(),0);
        for(int i=0;i<people.size();i++){
            for(auto s:people[i]){
                masks[i]|=(1<<m[s]);
            }
        }
        vector<int> ans;
        vector<bool> banned(people.size(),false);
        
       for(int i=0;i<masks.size();i++){
            for(int j=i+1;j<masks.size();j++){
                int lol=masks[i]|masks[j];
                if(lol==masks[i]){
                    banned[j]=true;
                }
                else if(lol==masks[j])
                    banned[i]=true;
            }
        } 
        int n=req_skills.size();
        recurse(masks,0,0,ans,banned,n);
        return gg;
        
        
    }
};