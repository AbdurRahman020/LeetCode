class Solution(object):
    def canMakeArithmeticProgression(self, arr:list[int]) -> bool:
        arr.sort()
        for i in range(1,len(arr)-1):
            if arr[i+1]-arr[i] != arr[i]-arr[i-1]:
                return False
        return True

if __name__ == '__main__':
    s = Solution()
    print(s.canMakeArithmeticProgression([3,5,1]))
    print(s.canMakeArithmeticProgression([1,2,4]))