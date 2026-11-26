class Solution:
    def brokenCalc(self, sV: int, t: int) -> int:
        ans=0
        while(t>sV):
            if(t%2!=0):
                ans=ans+1
                t=t+1
            else :
                ans=ans+1
                t=t//2
        # agr t chota hua sV se toh sV ko piche aana pdega 
        return ans+(sV-t)
    
       