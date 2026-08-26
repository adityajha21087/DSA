bool cmp(vector<int> & a, vector<int> & b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),cmp) ;
       int n=intervals.size();
       int count=0;
       int lastTime=intervals[0][1];

      for(int i=1; i<n; i++){
       int startTime=intervals[i][0];
       if(lastTime>startTime) count++;
       else lastTime=intervals[i][1];

      }
 return count;
    }
};