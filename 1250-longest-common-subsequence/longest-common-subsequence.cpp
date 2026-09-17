class Solution {
public:
       int f(string &text1 , string &text2, int i , int j,vector<vector<int>> &dp){
        // i foe text1, j for text2
        if(i==-1) return 0;
        if(j==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
        return dp[i][j]=1+f(text1,text2, i-1, j-1,dp);
        }
        else {
            int a=f(text1, text2, i-1,j,dp);
            int b=f(text1, text2 , i,j-1,dp);
            return dp[i][j]=max(a,b);
        }
       }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return f(text1,text2, n-1, m-1,dp);
    }
};