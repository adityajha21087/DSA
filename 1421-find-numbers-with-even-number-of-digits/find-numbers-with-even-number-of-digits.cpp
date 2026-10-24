class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n =nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            int num=nums[i];
            int count2=0; // ye hume num of digit count kar ke dega
            while(num>0){
              num=num/10;
            count2++;
            }
            if(count2%2==0) count++;
        }
        return count;
    }
};