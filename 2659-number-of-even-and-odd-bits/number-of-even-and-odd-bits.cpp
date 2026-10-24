class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans;
        while(n>0){
            if(n%2==0) ans.push_back(0);
            else ans.push_back(1);
            n=n/2;
        }
        int even=0;
        int odd=0;
        int m=ans.size();
        for(int i=0; i<m; i++){
            if(ans[i]==1){
                if(i%2==0) even++;
                else odd++;
            }
        }
        vector<int> ans2;
        ans2.push_back(even);
        ans2.push_back(odd);
        return ans2;
    }
};