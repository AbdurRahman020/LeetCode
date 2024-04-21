class Solution(object):
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        num = nums1 + nums2
        num.sort()
        if len(num)%2 != 0:
            return num[len(num)//2]
        else:
            m1 = num[(len(num)-1)//2]
            m2 = num[(len(num)-1)//2 + 1]
            return (float(m1)+float(m2))/2

if __name__ == '__main__':
    s = Solution()
    print(s.findMedianSortedArrays([1,3], [2]))
    print(s.findMedianSortedArrays([1,2], [3,4]))