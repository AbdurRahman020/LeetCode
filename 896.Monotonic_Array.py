class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:
        n = len(nums)
        increase = all(nums[i] <= nums[i + 1] for i in range(n - 1))
        decrease = all(nums[i] >= nums[i + 1] for i in range(n - 1))
        return increase or decrease 
    
       # method#2
       #if nums == sorted(nums) or nums == sorted(nums, reverse=True):
       #    return True
       #else:
       #   return False
    
if __name__ == '__main__':
    s = Solution()
    print(s.isMonotonic([1,3,2]))
    print(s.isMonotonic([6,5,4,4]))
    print(s.isMonotonic([1,2,2,3]))