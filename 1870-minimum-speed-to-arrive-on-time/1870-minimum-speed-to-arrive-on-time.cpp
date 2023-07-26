class Solution {
public:

    double findt(vector<int>dist,int h) {
        int n=dist.size();
        double gg=0.00;
        int sum=0;
        for(int i=0;i<n;i++) {
            if(i==n-1){
                gg= (double)sum;
                gg+=(double)dist[i]/h;

            }
            else{
            sum+=ceil(((double)dist[i]/h));
            }
            
        }
   
        return gg;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start=1,end=10000000,m;
        int ans=-1;
        while(start<=end) {
            // cout<<"start="<<start<<endl<<"end="<<end<<endl;
            m=start+(end-start)/2;
            // cout<<"mid="<<m<<endl;
            // cout<<findt(dist,m)<<endl<<findt(dist,m+1)<<endl;
            double temp = findt(dist,m);
            // cout<<m<<" "<<temp<<endl;
            
            if(temp<=hour){
            
                ans=m;
                end=m-1;
               
            }
            else{
            start=m+1;
            }
        }

        return ans;
    }
};