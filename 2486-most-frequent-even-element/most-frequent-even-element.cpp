class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
         if(nums[i]%2==0)   map[nums[i]]++;
        }
      priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>>pq;
      for(auto ele : map){
        pair<int,int> p;
        p.first=-1*ele.second;
        p.second=ele.first;
        pq.push(p);
      }
      if(pq.size()==0) return -1;
    pair<int,int> p=pq.top();

    return p.second;

    }
};