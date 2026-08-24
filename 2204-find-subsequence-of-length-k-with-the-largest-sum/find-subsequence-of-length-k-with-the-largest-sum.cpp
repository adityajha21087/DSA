class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
       for(int i=0 ;   i< nums.size(); i++) {
        pair<int,int > p;
        p.first=nums[i];
        p.second=i;
        pq.push(p);
        if(pq.size()>k) pq.pop();
       }

       priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq1;
       while(pq.size()>0){
        pair<int,int> p;
        pair<int,int> top=pq.top();

        p.first=top.second;
        p.second=top.first;
         
         pq1.push(p);
        pq.pop();
       }
       vector<int> ans;
       while(pq1.size()>0){
        ans.push_back(pq1.top().second);
        pq1.pop();
       }
     return ans;
    }
};