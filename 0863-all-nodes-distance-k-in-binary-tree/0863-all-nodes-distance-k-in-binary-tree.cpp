/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode *> q;
        q.push(root);
        unordered_map<int,vector<int>> graph;
        while(q.size()){
            TreeNode *rm = q.front();
            q.pop();
            if(rm->left){
                graph[rm->val].push_back(rm->left->val);
                graph[rm->left->val].push_back(rm->val);
                q.push(rm->left);
            }
            if(rm->right){
                graph[rm->val].push_back(rm->right->val);
                graph[rm->right->val].push_back(rm->val);
                q.push(rm->right);
            }
        }
        queue<pair<int,int>> bfs;
        bfs.push({target->val,k});
        vector<int> ans;
        unordered_map<int,bool> visited;
        while(bfs.size()){
            pair<int,int> rm=bfs.front();
            visited[rm.first]=true;
            bfs.pop();
            if(rm.second==0){
                // cout<<rm.first<<" "<<rm.second<<endl;
                ans.push_back(rm.first);
            }
            else{
                for(int ele:graph[rm.first]){
                    if(!visited[ele]){
                    bfs.push({ele,rm.second-1});
                    }
                }
            }
        }
        return ans;
        
    }
};