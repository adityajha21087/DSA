class Solution {
public:
    int f(int i, int sum, vector<int > &nums, int target){
      if(i==nums.size()){
        if(target==sum) return 1;
        else return 0;
      }
    // if(dp[i][sum]!=-1) return dp[i][sum];
    int usePlus=f(i+1, sum+nums[i], nums, target);
    int useNeg=f(i+1, sum-nums[i], nums,  target);
    return usePlus+useNeg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int> (target+1, -1));
        return f(0,0,nums,  target);
    }
};