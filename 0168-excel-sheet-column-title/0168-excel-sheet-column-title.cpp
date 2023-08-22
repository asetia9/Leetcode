class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            
            int c = (columnNumber%26)-1;
            if(c==-1){
                ans = 'Z'+ans;
            }
            else{
            char ch = c+'A';
            ans = ch+ans;
            }
            if(columnNumber%26==0){
                columnNumber=(columnNumber/26)-1;
            }
            else{
            columnNumber = columnNumber/26;
            }
          
            
        }
        return ans;
    }
};