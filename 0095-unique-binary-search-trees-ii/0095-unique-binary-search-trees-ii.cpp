/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> recurse(int low, int high){
        if(low==high){
            TreeNode * nh = new TreeNode(low);
            return {nh};
        }
        if(low>high){
            return {NULL};
        }
        vector<TreeNode *> ans;
        for(int i=low;i<=high;i++){
            vector<TreeNode *> left = recurse(low,i-1);
            vector<TreeNode *> right = recurse(i+1,high);
            for(TreeNode * r:right){
                for(TreeNode *l:left){
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return recurse(1,n);
    }
};