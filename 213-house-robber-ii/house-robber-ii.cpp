class Solution {
public:
    int f(vector<int> & nums ,vector<int> &dp ,  int i , int end ){
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i]+f(nums ,dp, i+2 , end);
        int skip = f(nums,dp, i+1, end);
        return dp[i]=max(take , skip );
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        if(n==1) return nums[0];
        
        int a = f(nums ,dp,  0 , n-2) ;
fill(dp.begin(), dp.end(), -1);
       int  b =f(nums , dp , 1 , n-1);
        return max( a, b);
    }
};