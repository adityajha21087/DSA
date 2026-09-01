class Solution {
public:
   int f(vector<int> & arr, int i, vector<int> &dp ){
    int n=arr.size();
    if(i==n-1) return arr[i];
    if(i==n-2)  return max(arr[i],arr[i+1]);
    if(dp[i]!=-1) return dp[i];
    return dp[i]= max((arr[i]+f(arr,i+2,dp)),0+f(arr,i+1,dp));
   }
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(arr,0, dp);
    }
};