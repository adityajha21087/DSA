class Solution {
public:
    string findValidPair(string s) {
        //step-1
        int n=s.size();
        unordered_map<char,int> map;
        for(int i=0; i<n ; i++){
            map[s[i]]++;
        }
        int i=0; 
        int j=i+1;
        string ans="";
        while(j<n){
      if((map.find(s[i])!=map.end()) && (map.find(s[j])!=map.end())){

   if(s[i]!=s[j]) {    if(((int(s[i])-'0')==map[s[i]]) && ((int(s[j])-'0')==map[s[j]])) {
            ans+=s[i];
            ans+=s[j];
            return ans;
        }}
        

      }

            i++;
            j++;
        }
        return "";
    }
};