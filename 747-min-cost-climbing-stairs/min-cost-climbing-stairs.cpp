class Solution {
public:
    int helper(vector<int> &cost, int i, vector<int> &dp){
        if(i<=1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+ min(helper(cost, i-1,dp), helper(cost, i-2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        int n=cost.size();
        return min(helper(cost, n-1 , dp), helper(cost, n-2, dp));
    }
};