//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool canColor(vector<int>adj[], int i, vector<int> &color, int prev){
        
        if(prev==-1) color[i]=0;
        else color[i]=!prev;
        bool ans=true;
        for(int ele:adj[i]){
            
            if(color[ele]==color[i]) return false;
            else if(color[ele]==-1){
                ans= ans&canColor(adj,ele,color,color[i]);
            }
        }
        
        return ans;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1&&!canColor(adj,i,color,-1)){
	            return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends