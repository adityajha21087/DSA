class Solution {
public:
    typedef pair<float,pair<int,int>>  pip; 
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      int n=arr.size();
      // priority queue mai hum value ith index and jth index put karenge
      priority_queue<pip,vector<pip>, greater<pip>> pq;
      for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            pip p;
            p.first=double(arr[i])/arr[j];
            p.second.first=arr[i];
            p.second.second=arr[j];
            pq.push(p);
        }
      }
        // abb min heap se hum k-1 element ko nikal ke bahar phek denge
        while(k>1){
            pq.pop();
            k--;
        }
       vector<int> ans(2);

       pip top=pq.top();
       ans[0]=top.second.first;
       ans[1]=top.second.second;
      return ans;
    }
};