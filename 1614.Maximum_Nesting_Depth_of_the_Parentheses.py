class Solution(object):
    def maxDepth(self, s: str) -> int:
        depth = 0
        opened = 0
        
        for bracket in s:
            if bracket == '(':
                opened += 1
                depth = max(depth, opened)
            elif bracket == ')':
                opened -= 1
                
        return depth
    
if __name__ == '__main__':
    s = Solution()
    print(s.maxDepth('(1+(2*3)+((8)/4))+1'))
    print(s.maxDepth('(1)+((2))+(((3)))'))