class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        max_area, stack = 0, [(0,0)]
        heights.append(0)
        
        for index, height in enumerate(heights) :
            start = index
            while stack[-1][0] > height:
                h, i = stack.pop()
                max_area = max(max_area, (index-i)*h)
                start = i 

            if height > stack[-1][0]:
                stack.append((height, start))
        
        return max_area

if __name__ == '__main__':
    s = Solution()
    print(s.largestRectangleArea([2,4]))
    print(s.largestRectangleArea([2,1,5,6,2,3]))