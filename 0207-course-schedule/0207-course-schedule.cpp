class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> outdegree(n,0);
        unordered_map<int,vector<int>> graph;
        for(auto &p:pre){
            graph[p[1]].push_back(p[0]);
            outdegree[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0)
                q.push(i);
        }
        if(!q.size())
            return false;
        while(q.size()){
            int rm = q.front();
            q.pop();
            for(int ele:graph[rm]){
                outdegree[ele]--;
                if(outdegree[ele]==0)
                    q.push(ele);
            }
        }
        for(int ele:outdegree)
            if(ele>0)
                return false;
        return true;
        
    }
};