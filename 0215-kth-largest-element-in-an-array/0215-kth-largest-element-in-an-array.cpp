class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int ele:nums){
            if(pq.size()<k)
                pq.push(ele);
            else if(pq.top()<ele){
                pq.pop();
                pq.push(ele);
            }
        }
        return pq.top();
    }
};