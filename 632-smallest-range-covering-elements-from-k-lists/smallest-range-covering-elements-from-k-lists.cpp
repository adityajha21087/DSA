class Solution {
public:
    typedef pair<int,pair<int,int>> pip;
    vector<int> smallestRange(vector<vector<int>>& nums) {
      priority_queue<pip,vector<pip>,greater<pip>>  pq;
      int mx=INT_MIN;
      int k=nums.size();

      for(int i=0; i<k; i++)
      {
        mx=max(mx,nums[i][0]);
        pq.push({nums[i][0],{i,0}});
      }

      int mn=pq.top().first;
      // inital range set kar diya hu
      int start=mn, end=mx;
     while(true) {
        pip temp=pq.top();
        int row=temp.second.first;
        int col=temp.second.second;
        pq.pop();

        //abb uss row ke next colom ko add karunga 
         if(col==nums[row].size()-1) break;
        pq.push({nums[row][col+1],{row,col+1}});
        mx=max(mx,nums[row][col+1]);
        mn=pq.top().first;
       // range comparison
       if(mx-mn<end-start){
        start=mn;
        end=mx;
       }

        
     }
     
     return {start,end};

    }
};