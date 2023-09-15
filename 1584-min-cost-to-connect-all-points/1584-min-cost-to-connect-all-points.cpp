class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> visited(points.size(),false);
        pq.push({0,0});
        int sum=0;
        while(pq.size()){
            pair<int,int> rm=pq.top();
            pq.pop();
            if(visited[rm.second]==true) continue;
            sum+=rm.first;
            visited[rm.second]=true;
            for(int i=0;i<points.size();i++){
                if(i==rm.second) continue;
                if(visited[i]==false)
                    pq.push({abs(points[i][0]-points[rm.second][0])+abs(points[i][1]-points[rm.second][1]),i});
            }
        }
        
        return sum;
        
    }
};