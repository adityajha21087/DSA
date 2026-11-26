class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        x=num
        if(num==0):
            return True
        else :
            ans=0
            while num>0:
                rem=num%10
                ans=ans*10+rem
                num=num//10
            
            ans1=0
            num=ans
            while num>0:
                rem=num%10
                ans1=ans1*10+rem
                num=num//10
        if(x==ans1):
            return True
        else :
            return False

        
        
           

       