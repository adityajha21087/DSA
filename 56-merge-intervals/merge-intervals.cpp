  bool cmp(vector<int> & a, vector<int> &b){
    return a[1]<b[1];
  }
class Solution {
public:
// sorting on the basis of end time

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        vector<vector<int>> result ;
        result.push_back(intervals[n-1]);
        for(int i=n-2; i>=0; i--){
            vector<int> lastInterval=result[result.size()-1];
            vector<int> curr=intervals[i];

            // main work 
            if(curr[1]>=lastInterval[0]){
               
                // curr-> last >=lastInterval ka first ->overlapping
          result[result.size()-1][0]=min(result[result.size()-1][0],curr[0]);
        result[result.size()-1][1]=max(result[result.size()-1][1],curr[0]);


            }
            else {
                result.push_back(intervals[i]);

            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};