from typing import List

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max([sum(customer) for customer in accounts])

if __name__ == '__main__':
    s = Solution()
    print(s.maximumWealth([[1,2,3],[3,2,1]]))
    print(s.maximumWealth([[1,5],[7,3],[3,5]]))
    print(s.maximumWealth([[2,8,7],[7,1,3],[1,9,5]]))