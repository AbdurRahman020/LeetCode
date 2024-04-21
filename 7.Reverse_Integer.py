class Solution(object):
    def reverse(self, x: int) -> int:
        int_reversed = ''
        sign = 1
        for i in str(x):
            if i == '-':
                sign = -1
            else:
                int_reversed += i
        int_reversed = sign*int(int_reversed[::-1])
        if int_reversed > 2**31 - 1 or int_reversed < -2**31:
            return 0
        return int_reversed

#        method # 2
#        int_reversed = 0
#        if x >= 0:
#           int_reversed = int(str(x)[::-1])
#        else:
#           int_reversed = int(str(x)[1:][::-1])*-1
#        
#        if int_reversed < -2**31 or int_reversed > 2**31 - 1:
#           return 0        
#       return int_reversed

if __name__ == '__main__':
    s = Solution()
    print(s.reverse(-123))
    print(s.reverse(1534236469))
    print(s.reverse(120))