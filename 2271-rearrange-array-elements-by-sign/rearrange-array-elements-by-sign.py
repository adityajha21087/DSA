class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        list1=[]
        list2=[]
        for i in nums:
            if(i>0):
                list1.append(i)
            else :
                list2.append(i)
        print(list1)
        print(list2)
        for i in range (len(nums)):
            if i%2==0:
                nums[i]=list1[i//2]
            else :
                nums[i]=list2[i//2]
        return nums