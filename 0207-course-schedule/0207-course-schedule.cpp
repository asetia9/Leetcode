class Solution {
public:
    bool cycleDetect(unordered_map<int,vector<int>> &graph,int idx,vector<bool>&pathVisited,vector<bool>&visited){
        if(pathVisited[idx]){
            return true;
        }
        visited[idx]=true;
        pathVisited[idx]=true;
        for(int ele:graph[idx]){
            if(!visited[ele]&&cycleDetect(graph,ele,pathVisited,visited))
                return true;
            else if(pathVisited[ele])
                return true;
        }
        pathVisited[idx]=false;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> graph;
        for(auto p:pre){
            graph[p[0]].push_back(p[1]);
        }
       
            vector<bool> pathVisited(numCourses,false);
        vector<bool> visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            
            if(!visited[i]&&cycleDetect(graph,i,pathVisited,visited)){
                return false;
            }

        }
        return true;
        
    }
};