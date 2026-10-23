class Solution {
public:
    int maximumWealth(vector<vector<int>>& num) {
        int m=num.size();
        int n=num[0].size();
        for(int i=0; i<m; i++){
            int sum=0;
            for(int j=0; j<n; j++){
                sum+=num[i][j];
            }
            num[i][0]=sum;
        }
        int maxi=INT_MIN;
        for(int i=0; i<m; i++){
         maxi=max(maxi,num[i][0]);
        }
        return maxi;
    }
};