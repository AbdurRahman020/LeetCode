class Solution:
    def maxPower(self, s: str) -> int:
        count , power = 0, 0
        
        for i in range(1,len(s)):
            if s[i-1] == s[i]:
                count += 1
                power = max(count, power)
            else:
                count = 0
                
        return power + 1

if __name__ == '__main__':
    s = Solution()
    print(s.maxPower("leetcode"))
    print(s.maxPower("abbcccddddeeeeedcba"))