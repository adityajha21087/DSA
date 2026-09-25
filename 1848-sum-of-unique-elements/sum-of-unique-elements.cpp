class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto ele : nums){
            map[ele]++;
        }
        int sum=0;
        for(auto ele : map){
            if(ele.second<2) sum+=ele.first;
        }
        return sum;
    }
};