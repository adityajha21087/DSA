class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int n= answers.size();
        int result=0;

        for(int i=0; i<n; i++){
            if(!mp[answers[i]+1]){
                result+=answers[i]+1; // we started a new colour group
                if(answers[i]==0 ) continue;
                mp[answers[i]+1]++;

            }
            else {
                mp[answers[i]+1]++;
                int key=answers[i]+1;
                int val= mp[key];
                if(key==val){
                    // we found the all  the rabbit from the group
                    mp.erase(key);
                }
            }
        }
        return result;
    }
};