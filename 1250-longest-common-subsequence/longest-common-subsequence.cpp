class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m=a.size();
        int n=b.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
                }
            }
        }
     string ans="";
     int i=m;
     int j=n;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]) ans+=(a[i-1]);
       if(dp[i-1][j]>dp[i][j-1]) i--;
       else j--;
    } 
    cout<<ans;
        return dp[m][n];
    }
};