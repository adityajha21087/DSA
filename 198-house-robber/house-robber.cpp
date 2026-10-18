class Solution {
public:

// Input: nums = [1,2,3,1]
// Output: 4
   int f(int i , vector<int>& nums, int sum,vector<int> &dp){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
   int a=f(i+1,nums, sum,dp);
   int b=nums[i]+f(i+2, nums,sum,dp );
   sum+=max(a,b);
    return dp[i]= sum ;
   }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,0,dp);
    }
};