class Solution {
public:
    int mini(string &s1, string &s2, int i, int j,vector<vector<int>> &dp){
        if(j==s2.size()&&i==s1.size()){
            return 0;
        }
        if(j==s2.size()){
            int s=0;
            int ti=i;
            while(ti<s1.size()){
                s+=s1[ti];
                ti++;
            }
            return dp[i][j]=s;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j]){
            return mini(s1,s2,i+1,j+1,dp);
        }
        int minimum = INT_MAX;
        int sum=0;
        for(int x=i;x<s1.size();x++){
            if(s1[x]==s2[j]){
                minimum=min(minimum,sum+mini(s1,s2,x+1,j+1,dp));
                break;
            }
            sum+=s1[x];
        }
        minimum=min(minimum,s2[j]+mini(s1,s2, i,j+1,dp));
        return dp[i][j]=minimum;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        string x="";
        string y="";
        if(s1.size()>=s2.size()){
            x=s1;
            y=s2;
        }
        else{
            x=s2;
            y=s1;
        }
        vector<vector<int>> dp(x.size()+1, vector<int>(y.size()+1,-1));
        return mini(x,y,0,0,dp);
    }
};