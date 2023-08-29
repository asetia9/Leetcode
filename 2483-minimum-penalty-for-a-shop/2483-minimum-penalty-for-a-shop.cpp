class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> prefix;
        vector<int> suffix(n,-1);
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                count1++;
            }
            if(customers[n-i-1]=='Y'){
                count2++;
            }
            prefix.push_back(count1);
            suffix[n-i-1]=count2;
        }
        int mini=INT_MAX;
        int min_hour=0;
        for(int i=0;i<=n;i++){
            if(i==0){
             if(mini>suffix[i]){
                 mini=suffix[i];
                 min_hour=0;
             }   
            }
            else if(i==n){
                if(mini>prefix[i-1]){
                    mini=prefix[i-1];
                    min_hour=i;
                }
            }
            else{
                if(mini>prefix[i-1]+suffix[i]){
                    mini=prefix[i-1]+suffix[i];
                    min_hour=i;
                }
            }
        }
        return min_hour;
    }
};