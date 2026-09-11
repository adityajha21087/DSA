class Solution {
public:
    bool divisorGame(int n) {
     vector<bool > dp(1001)   ;
     for(int i =1; i<=n; i++ ){
         if(i%2==0) dp[i]=true;
         else dp[i]=false;
     }
     return dp[n];
    }
};