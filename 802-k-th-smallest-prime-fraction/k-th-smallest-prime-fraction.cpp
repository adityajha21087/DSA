class Solution {
public:
    typedef pair<float,pair<int,int>>  pip; 
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      int n=arr.size();
       // k size ka max heap bana lenge
       priority_queue<pip> pq ;
      for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            pip p;
            p.first=double(arr[i])/arr[j];
            p.second.first=arr[i];
            p.second.second=arr[j];
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
      }
       
       vector<int> ans(2);

       pip top=pq.top();
       ans[0]=top.second.first;
       ans[1]=top.second.second;
      return ans;
    }
};