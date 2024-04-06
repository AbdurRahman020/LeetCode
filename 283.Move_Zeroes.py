class Solution(object):
    def moveZeroes(self, nums: list[int]):
        j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[j], nums[i] = nums[i], nums[j]
                j += 1
        return nums
                
if __name__ == '__main__':
    s = Solution()
    print(s.moveZeroes([0,1,0,3,12]))
    print(s.moveZeroes([0]))