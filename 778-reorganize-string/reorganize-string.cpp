class Solution {
public:
    string reorganizeString(string s) {
       int n=s.size();
       unordered_map<char,int> map;
       for(int i=0; i<n; i++){
        map[s[i]]++;
       } 
       //priorty_queue banayenge jisme freq mera first element hoga 
        
     priority_queue<pair<int,char> > pq;
     for(auto ele: map){
        pair<int,char> p;
        p.first=ele.second;
        p.second=ele.first;
       pq.push(p);
     }
     pair<int,char> top=pq.top();

     if(top.first>(n+1)/2) return "";

     string ans="";
     while(pq.size()>0){
     pair<int ,char> top=pq.top();
     ans+=top.second;
     map[top.second]--;
     pq.pop();
     if(pq.size()>0){
        
        pair<int,char> secEle=pq.top();
        ans+=secEle.second;
        map[secEle.second]--;
        pq.pop();
        if(map[secEle.second]>0) pq.push({map[secEle.second],secEle.second});
     }
   if(map[top.second]>0) pq.push({map[top.second],top.second});
     }
     while(pq.size()>0){
        pair<int,char> top=pq.top();
        ans+=top.second;
        pq.pop();
     }
 return ans;
    }
};