class Solution {
public:
     bool isPerfect(int n ){
        int sqr=sqrt(n);
        return sqr*sqr==n;
     }
    int f(int n , vector<int> & dp){
        if(isPerfect(n)) return 1;
        int mini=INT_MAX;
        if(dp[n]!=-1) return dp[n];
        for(int i=1; i*i<=n; i++){
            int count=f(n-(i*i), dp)+f(i*i, dp);
            mini=min(count, mini);
        }
        return dp[n]=mini;
    }
    int numSquares(int n) {
       vector<int> dp(n+1,-1);
        return f(n , dp); 
    }
};