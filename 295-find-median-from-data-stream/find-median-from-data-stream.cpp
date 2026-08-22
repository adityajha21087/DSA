class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> right;
    priority_queue<int> left;
    MedianFinder() {// default constructor

        
    }
    
    void addNum(int num) {
       
       if(left.size()==0 || num<left.top()) left.push(num);
       else right.push(num);

       int n=left.size();
       int m=right.size();
       if(m>n && m-n>1) {
        int top=right.top();
        right.pop();
        left.push(top);

       }
       if(n>m && n-m>1){
        int top=left.top();
        left.pop();
        right.push(top);
       }
     
    }
    
    double findMedian() {
         int n=left.size();
         int m=right.size();
         if(n==m) return( left.top()+right.top())/2.0;
         if(n>m) return left.top();
         else return right.top();
        }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */