class Solution:
    def countOdds(self, low: int, high: int) -> int:
        # calculate the number of odd integers between low and high (inclusive)
        # since the difference between any two consecutive odd numbers is 2,
        # we can simply count the number of multiples of 2 within the range (high - low).
        # Therefore, odd = (high - low) // 2.
        odd = (high-low)//2
        # if either low or high is odd, we need to increment the count by 1
        # as the range includes one additional odd number.
        if low % 2 == 1 or high % 2 == 1:
            odd += 1
        # return the count of odd numbers within the given range.
        return odd

if __name__ == '__main__':
    s = Solution()
    print(s.countOdds(3, 7))
    print(s.countOdds(8, 10))