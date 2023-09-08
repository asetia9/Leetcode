class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex==0)
            return {1};
        vector<int> prev = {1,1};
        for(int i=2;i<=rowIndex;i++){
            vector<int> curr;
            curr.push_back(1);
            for(int j=0;j<prev.size()-1;j++){
                curr.push_back(prev[j]+prev[j+1]);
            }
            curr.push_back(1);
            prev=curr;
        }
        return prev;
    }
};