class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str="";
       for(int i=0;i<s.size();i++){
               str+=s[i];
               string temp=str;
               // cout<<temp<<endl;
               while(temp.size()<s.size()){
                   temp+=str;
               }
               if(temp==s&&temp.size()!=str.size())
                   return true;
       }
        return false;
    }
};