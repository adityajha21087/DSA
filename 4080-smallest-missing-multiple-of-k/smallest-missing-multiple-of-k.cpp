class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> s;
        for(int i=0; i<n; i++){
         s.insert(nums[i]);
        }

        int i=0;
        int a=k;
        int ans=k;
        while(i<n ){
            if(s.find(k)!=s.end()){
                k+=a;
                ans=k;
            }
            else{

                break;
            }
            i++;
        }
        return ans;
    }
};