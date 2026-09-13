class Solution {
public:
bool isPerfect(int n){
    int sqr=sqrt(n);
    return sqr*sqr==n;
}
    int numSquares(int n) {
      
        vector<int> dp(n+1);

        for(int i=1; i<=n; i++){
            if(isPerfect(i)) dp[i]=1;
            else{
                  int mini=INT_MAX;
                for(int j=1; j*j<=i; j++){
                   int  count = dp[j*j]+dp[i-j*j];
                   mini=min(mini,count);
                }
                dp[i]=mini;
            }
        }
     return dp[n];
    }
};