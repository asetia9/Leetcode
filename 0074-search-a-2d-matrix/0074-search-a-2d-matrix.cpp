class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low =0;
        int high = matrix.size()-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(matrix[mid][0]<target){
                low=mid+1;
            }
            else if(matrix[mid][0]==target)
                return true;
            else
                high=mid-1;
            
        }
        if(high==-1){
            return false;
        }
        int pr=high;
        low=0;
        high=matrix[0].size()-1;
        
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(matrix[pr][mid]==target){
                return true;
            }
            else if(matrix[pr][mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
        
        
    }
};