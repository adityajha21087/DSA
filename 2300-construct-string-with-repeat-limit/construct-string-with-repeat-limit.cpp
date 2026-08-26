class Solution {
public:
    string repeatLimitedString(string s, int k) {
        // maxHeap and map of(char and int )
    unordered_map<char,int> map;
    priority_queue<char>  pq;
    for(auto ele: s){
        map[ele]++;
    }
     
     for(auto ele: map){
        pq.push(ele.first);
     }

     string ans="";
    
     while(pq.size()>0){
      char ch=pq.top();
      pq.pop();
      if(map[ch]<=k){
        
        while(map[ch]>0){
            ans+=ch;
          
            map[ch]--;
        }
      }
      else {
        int i=1;
        while(i<=k){
            ans+=ch;
            map[ch]--;
            i++;   
        }
        if(pq.size()>0){
                char ch2=pq.top();
            pq.pop();
            ans+=ch2;
            map[ch2]--;
            if(map[ch2]>0) pq.push(ch2);
             if(map[ch]>0) pq.push(ch);
        }
       else {
        break;
      } 
       
      }
     
     }
         
 return ans;
    }
};