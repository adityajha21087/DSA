class Solution {
public:

    int helper(int sr,int sc, int er, int ec,vector<vector<int>>& arr, vector<vector<int> > &dp){
        if(sr==er-1 && sc==ec-1) return 1;
        int rightways=0;
        int leftways=0;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        if((sc<ec-1)   && arr[sr][sc+1]!=1)  rightways=helper(sr, sc+1, er, ec , arr, dp);

         if( (sr<er-1) &&  arr[sr+1][sc]!=1)  leftways=helper(sr+1, sc, er, ec , arr, dp);
         return dp[sr][sc]= rightways+leftways;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        if(obstacleGrid[0][0]==1) return 0;
        return helper(0,0,m, n, obstacleGrid, dp);
    }
};