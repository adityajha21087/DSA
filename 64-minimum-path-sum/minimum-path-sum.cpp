class Solution {
public:
   int  f(vector<vector<int>> &dp,vector<vector<int> > & grid, int er, int ec , int sr , int sc){
        if(er== sr && ec==sc) {
            return grid[er][ec];
        }
        if(er<sr || ec< sc) {
            return INT_MAX;
        }
        if(dp[sr][sc]!=-1)  return dp[sr][sc];

        int rightWays=f(dp,grid,er,ec, sr, sc+1);
        int downWays=f(dp,grid, er, ec,sr+1,sc);
        return dp[sr][sc]= grid[sr][sc]+min(rightWays,downWays);
     }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int> > dp(m, vector<int> (n,-1));
        return f(dp,grid, m-1 ,n-1, 0, 0);
    }
};