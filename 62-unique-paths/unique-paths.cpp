class Solution {
public:
    int f( vector<vector<int>> &dp, int sr, int sc , int er , int ec)
    {
        if(sr==er && sc==ec) return 1;
        if(sr>er) return 0;
        if(sc>ec) return 0;
         if (dp[sr][sc]!=-1) return dp[sr][sc];
        int rightWays=f(dp,sr,sc+1,er,ec);
        int downWays=f(dp,sr+1, sc, er ,ec);
        return dp[sr][sc]=rightWays+downWays;

    }
    int uniquePaths(int m, int n) {
   
   vector<vector<int>> dp(m,vector<int> (n,-1));
    int sr=0;
    int sc=0;
    int er=m-1;
    int ec=n-1;

       return f(dp,sr,sc,er,ec);
    }
};