class Solution(object):
    def twoSum(self, nums:list[int], target:int) -> list:
        checked = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in checked:
                return [checked[diff],i]
            else:
                checked[nums[i]] = i

if __name__ == '__main__':
    l = Solution()
    print(l.twoSum([2,7,11,15], 9))
    print(l.twoSum([3,2,4], 6))
    print(l.twoSum([-1,-2,-3,-4,-5], -8))