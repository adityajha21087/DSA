class Solution {
public:
    long f(int i, int sum  , vector< int> &coins, vector<vector<int> > & dp, int amount){
        if(i==coins.size()){
            if(sum==amount) return 0;
            else return INT_MAX;
        }

        if(dp[i][sum]!=-1) return dp[i][sum];
        long skip=f(i+1, sum, coins, dp, amount);

        if(coins[i]>amount-sum) return dp[i][sum]=skip;

        long pick=1+f(i,sum+coins[i], coins, dp, amount);
        return dp[i][sum]=min(skip, pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        vector<vector<int> > dp(n , vector<int> (amount+1,-1));

        int ans= (int)f(0, 0, coins, dp, amount);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};