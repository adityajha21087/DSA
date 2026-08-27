bool cmp(vector<int> &a , vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int n=points.size();
        int count=0;
        int lastPoint=points[0][1];
    for(int i=1; i<n; i++){
      int currPoint=points[i][0];
      if(lastPoint>=currPoint) count++;
      else lastPoint=points[i][1];
    }
    cout<<count;
    return n-count;
    }
};