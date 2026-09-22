class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n =nums.size();
        unordered_set<int> s;
        int  a=0;
        for(int i=0; i<n ; i++){
            s.insert(nums[i]);
            if(nums[i]==0) a=1;;
        }
        return  s.size()-a;
    }
};