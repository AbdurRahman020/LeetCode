from collections import Counter

class Solution(object):
    def maxFrequencyElements(self, nums: list[int]) -> int:
        x = Counter(nums)
        max_frq = -1
        
        for i in x:
            max_frq = max(max_frq, x[i])
            
        sum = 0
        for i in x:
            if x[i] == max_frq:
                sum += x[i]
        
        return sum
    
if __name__ == '__main__':
    s = Solution()
    print(s.maxFrequencyElements([1,2,2,3,1,4]))
    print(s.maxFrequencyElements([1,2,3,4,5]))