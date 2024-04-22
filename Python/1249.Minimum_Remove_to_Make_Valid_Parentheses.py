class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        s = list(s)

        for index, char in enumerate(s):
            if char == "(":
                stack.append(index)
            elif char == ")":
                if stack:
                    stack.pop()
                else:
                    s[index] = ''
        
        while stack:
            s[stack.pop()] = ''
        
        return ''.join(s)
    
if __name__ == '__main__':
    s = Solution()
    print(s.minRemoveToMakeValid("lee(t(c)o)de)"))
    print(s.minRemoveToMakeValid("a)b(c)d"))
    print(s.minRemoveToMakeValid("))(("))