class Solution {
public:
    int sumOfDigitANDpr(int n){
        int x=0;
        int pr=1;
        while(n>0){
        x=x+n%10;
        pr*=n%10;
        n=n/10;
        }
        return x+pr;
    }
  
    bool checkDivisibility(int n) {
       int x=sumOfDigitANDpr(n);
      if(n%x==0) return true;
      else return false;
    }
};