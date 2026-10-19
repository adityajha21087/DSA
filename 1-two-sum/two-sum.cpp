class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     int n=nums.size();
     unordered_map<int,int> map;
     vector<int> ans(2);
     for(int i=0; i<n ; i++){
        if(map.find(target-nums[i])!=map.end()){
        ans[0]=map[target-nums[i]];
        ans[1]=i;        }
        else{
            map[nums[i]]=i;
        }
        
     } 
     return ans;  
    }
};