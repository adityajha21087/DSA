class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                    
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
      int sum1=0;
      for(int i=0; i<m; i++){
        sum1+=s1[i];
      }
      int sum2=0;
      for(int j=0; j<n; j++){
        sum2+=s2[j];
      }
    return (sum1-dp[m][n])+(sum2-dp[m][n]);
    }
};