class Solution {// [5,5,5,10,20]

public:
    bool lemonadeChange(vector<int>& nums) {
     unordered_map<int,int> map;// val and freq ki map
    
    int a=-1;
    int n=nums.size();
    for(int i=0; i<n; i++){
       if(nums[i]==5){
        map[5]++;
       }

      else if(nums[i]==10){
        //  toh 5 dollar wapas karna hai
        if(map.find(5)==map.end()) {
            // 5 dollar nahi hai
            a=0;
            break;
        }
        else{
            map[5]--;
            map[10]++;
            if(map[5]==0) map.erase(5);

        }
       }
       else {
        if((map.find(10)!=map.end()) && (map.find(5)!=map.end())){
            map[10]--;
            map[5]--;
            if(map[5]==0) map.erase(5);
            if(map[10]==0) map.erase(10);

        }
        else if((map.find(5)!=map.end() )&& map[5]>=3 ){
            map[5]-=3;
            if(map[5]==0) map.erase(5);
        }
        else {
            a=0;
            break;
            cout<<a;
        }
    }
    }
   if(a==0) return false;
   else return true;

    }
};