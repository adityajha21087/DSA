class Solution {
public:

   string lcs1(string a, string b) {
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
        if(a[i-1]==b[j-1]) {ans+=(a[i-1]);
        i--;
        j--;
        }
       else if(dp[i-1][j]>dp[i][j-1]) i--;
       else j--;
    } 
   
    reverse(ans.begin(),ans.end());
    return ans;
   }
    string shortestCommonSupersequence(string a, string b) {
       string lcs=lcs1(a,b) ;
      int i=0; int j=0; int k=0 ;
      // i for a, j for b, k for lcs
     string scs="";
     while(i<a.size() && j< b.size() && k<lcs.size()){
        while(i<a.size() && a[i]!=lcs[k]){
            scs+=a[i];
            i++;
        }
        while(j<b.size() && b[j]!=lcs[k]){
            scs+=b[j];
            j++;
        }
     
            scs+=lcs[k];
            k++;
            i++;
            j++;
        
     }
     {
        while(j<b.size()){
            scs+=b[j];
            j++;
        }
     }
     {
        while(i<a.size()){
            scs+=a[i];
            i++;
        }
     }
     cout<<lcs;
      return scs;
    }
};