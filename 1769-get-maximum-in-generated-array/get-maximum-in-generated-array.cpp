class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1,0);
        if(n==0 ) return 0;
        nums[0]=0;
        nums[1]=1;

        for(int i=2; i<=n; i++){
           if(i%2==0) nums[i]=nums[i/2];
           else nums[i]=nums[i/2+1]+nums[i/2];

        }

        int maxc=0;
        for(int i=0 ; i<=n ; i++){
            maxc=max(nums[i],maxc);
        }
        return maxc;
    }
};