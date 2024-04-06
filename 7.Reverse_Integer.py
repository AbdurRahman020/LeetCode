class Solution(object):
    def reverse(self, x:int) -> int:
        num = ''
        sign = 1
        for i in str(x):
            if i == '-':
                sign = -1
            else:
                num += i
        num = sign*int(num[::-1])
        if num > 2**31 - 1 or num < -2**31:
            return 0
        return num

if __name__ == '__main__':
    s = Solution()
    print(s.reverse(-123))
    print(s.reverse(1534236469))
    print(s.reverse(120))