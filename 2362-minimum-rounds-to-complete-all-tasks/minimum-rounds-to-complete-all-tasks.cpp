class Solution {
public:
    int f(int count){
        if(count==0) return 0;
        if(count==2) return 1;
        if(count==3) return 1;


        if(count>3 && count%3==0){
         return 1+f(count-3);
        }
        if(count>2 && count%3==2){
         return 1+f(count-3);
        }
        if(count%3==1){
           return 1+f(count-2);
        }
        return -1;
    }
    int minimumRounds(vector<int>& tasks) {
       unordered_map<int, int > map;
       for(auto ele : tasks) {
        map[ele]++;
       }
       int round=0;
       for(auto ele : map ){
        int x=ele.first;
        int count =ele.second;
        if(count==1) {
            return -1;
        }
        // else round count karlenge
        
        round+=f(count);
       }
       return round;
    }
};