class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                queue<int> q;
                q.push(i);
                while(q.size()){
                    int rm = q.front();
                    q.pop();
                    for(int ele:graph[rm]){
                        if(color[ele]==color[rm]) return false;
                        else if(color[ele]==-1){
                            color[ele]=!color[rm];
                            q.push(ele);
                        }
                    }
                    
                }
            }
        }
        return true;
        
    }
};