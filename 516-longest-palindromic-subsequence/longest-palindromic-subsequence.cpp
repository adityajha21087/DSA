class Solution {
public:
   int f(string & a, string &s, int i, int j,vector<vector<int>> &dp){
    if(i==-1) return 0;
    if(j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==a[j]){
        return dp[i][j]= 1+f(a,s,i-1,j-1,dp);
    }
    else{
        int x=f(a,s,i-1,j,dp);
        int y=f(a,s,i,j-1,dp);
        return dp[i][j]=max(x,y);
    }
   }
    int longestPalindromeSubseq(string s) {
       string a =s;
       reverse(a.begin(),a.end());
       cout<<a;
       int n=s.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return f(a,s,n-1,n-1,dp); 
    }
};