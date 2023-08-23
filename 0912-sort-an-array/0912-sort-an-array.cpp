class Solution {
public:
    
   vector<int> merge(vector<int>&left, vector<int>&right){
       int i=0;
       int j=0;
       vector<int> ans;
       while(i<left.size()&&j<right.size()){
            if(left[i]<right[j]){
                ans.push_back(left[i++]);
            }
           else{
               ans.push_back(right[j++]);
           }
       }
       while(i<left.size())
           ans.push_back(left[i++]);
       while(j<right.size())
           ans.push_back(right[j++]);
       return ans;
       
   }
    vector<int> mergeSort(vector<int> &nums, int low, int high){
            
       if(low==high){
           return {nums[low]};
       } 
        int mid = low+(high-low)/2;
        vector<int> left = mergeSort(nums, low, mid);
        vector<int> right = mergeSort(nums,mid+1,high);
        return merge(left,right);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        return mergeSort(nums,0,nums.size()-1);
    }
};