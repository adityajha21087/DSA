class Solution:
    def reverseBits(self, n: int) -> int:
        # int to binary 
        str1=""
        count=0
        if(n==0):
            return 0
        while  n>0:
            if n%2==0:
                str1=str(0)+str1
                n=n//2
            else :
                str1=str(1)+str1
                n=n//2
            count=count+1
        a=32-count
        while a>0:
            str1=str(0)+str1
            a=a-1
        
        ans=0
        pow1=0
        for i in range (0,len(str1)):
            if(str1[i]=='0'):
                ans=ans+0*(2**pow1)
                pow1=pow1+1
            else :
                ans=ans+1*(2**pow1)
                pow1=pow1+1
        return ans



        return ans
        