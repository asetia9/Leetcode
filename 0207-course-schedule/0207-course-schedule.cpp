class Solution {
public:
    
    bool dfs(vector<int> graph[],int idx,vector<bool>& visited,vector<bool>&order){
        visited[idx]=true;
        order[idx]=true;
        for(int ele:graph[idx]){
            if(!visited[ele]&&dfs(graph,ele,visited,order)){
                return true;
            }
            if(order[ele]==true){
                return true;
            }
            
            
        }
        
        order[idx]=false;
        return false;
    }
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        for(vector<int> edge:prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }
        bool ans;
        vector<bool> visited(numCourses,0);
        vector<bool> order(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]&&dfs(graph,i,visited,order)==true){
                return false;
                
            }
        }
        return true;
    }
};