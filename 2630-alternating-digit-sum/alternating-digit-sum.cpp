class Solution {
public:
    int alternateDigitSum(int n) {
        string s =to_string(n);
        reverse(s.begin(),s.end());
        // string to integer
        int a=stoi(s);
        int sum=0;
        int i=0;
        while(a>0){
        if(i%2==0){ sum+=-1*(a%10);
        a=a/10;}
        else {
           sum+=a%10;
           a=a/10; 
        }
        i++;
        }
        return -1*sum;
    }
};