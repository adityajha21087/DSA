class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
       priority_queue<int ,vector<int>, greater<int>> pq;

       for(auto ele : nums){
        pq.push(ele);
    
       }

       while(k>0){
        if(pq.top()==0){
            k=0;
        }
        else{
            int b=pq.top();
            pq.pop();
            pq.push(-1*b);
            k--;
        }
       }
    int sum=0;
     while(pq.size()>0){
        int a=pq.top();
        sum+=a;
        pq.pop();
     }
     return sum;
    }
};