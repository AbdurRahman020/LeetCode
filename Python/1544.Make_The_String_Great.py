class Solution(object):
    def makeGood(self, s: str) -> str:
        stack = []
        
        for ch in s:
            if stack and abs(ord(ch)-ord(stack[-1])) == 32:
                stack.pop()
            else:
                stack.append(ch)
                
        return ''.join(stack)

if __name__ == '__main__':
    s = Solution()
    print(s.makeGood("leEeetcode"))
    print(s.makeGood("abBAcC"))
    print(s.makeGood("s"))