class Solution(object):
    def divide(self, dividend:int, divisor:int) -> int:
        if dividend == 0:
            return 0
        if divisor == 0:
            return RuntimeError("Divison by ZERO")
        if dividend == -2**31 and divisor == -1:
            return (2**31)-1
        if (dividend < 0 and divisor < 0) or ((dividend > 0 and divisor > 0)):
            sign_pos = True
        else:
            sign_pos = False

        dividend, divisor = abs(dividend), abs(divisor)

        quotient = 0
        for i in reversed(range(dividend.bit_length() - divisor.bit_length() + 1)):
            if dividend >> i >= divisor:
                dividend -= divisor << i
                quotient |= 1 << i
                
        return quotient if sign_pos else -quotient 
            
if __name__ == '__main__':
    s = Solution()
    print(s.divide(1, 0))
    print(s.divide(7, -3))
    print(s.divide(2**31-1, -2**20))