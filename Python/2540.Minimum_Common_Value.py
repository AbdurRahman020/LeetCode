class Solution(object):
    def getCommon(self, nums1: list[int], nums2: list[int]) -> int:
        i, j, n1, n2 = 0, 0, len(nums1), len(nums2) 
        
        while i < n1 and j < n2:
            if nums1[i] == nums2[j]:
                return nums1[i]
            elif nums1[i] < nums2[j]:
                i+=1
            else:
                j+=1
                
        return -1
    
if __name__ == '__main__':
    s = Solution()
    print(s.getCommon([1,2,3], [2,4]))
    print(s.getCommon([1,2,3,6], [2,3,4,5]))