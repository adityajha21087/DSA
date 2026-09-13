class Solution {
public:
    int countSquares(vector<vector<int>>& nums) {
        int m=nums.size();
        int n=nums[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0 ) continue;
                if(nums[i][j]==0) continue;
                else {
                    nums[i][j]+=min(nums[i-1][j-1], min(nums[i-1][j], nums[i][j-1]) );
                }
            }
        }
        int sum=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum+=nums[i][j];
            }
        }
        return sum;
    }
};