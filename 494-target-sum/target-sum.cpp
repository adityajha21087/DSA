class Solution {
public:
 
    int f(int i, int res, vector<int> &nums, vector<vector<int>> & dp, int target, int sum){
        if(i==nums.size()){
            if(res==target) return 1;
            else return 0;
        }
       if (dp[i][res+sum]!=-1) return dp[i][res+sum];
       int add=f(i+1, res+nums[i],nums, dp, target,sum);
       int sub=f(i+1, res-nums[i], nums, dp, target,sum);
       return dp[i][sum+res]=add+sub;
    }
  
    int findTargetSumWays(vector<int>& nums, int target) {
        int n =nums.size();
        int sum=0;
    for(auto ele: nums){
        sum+=ele;
    }
    vector<vector<int>> dp(n, vector<int> (2*sum+1,-1));
    return f(0, 0, nums, dp,  target,sum);
    }
};                                                                                                                                                