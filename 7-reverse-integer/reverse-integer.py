class Solution:
    def reverse(self, x: int) -> int:
        if x==0  :
            return 0
        elif x>0 :
            ans=0
            while x>0:
               rem=x%10
               ans=ans*10+rem
               x=x//10
            if ans<=2**31-1:
                return ans
            else :
                return 0

        else :
            ans=0
            x=-1*x
            while (x>0):
                rem=x%10
                ans=ans*10+rem
                x=x//10 
            ans=ans*-1
            if ans<-1*2**31:
                return 0
            else :
                return ans
        