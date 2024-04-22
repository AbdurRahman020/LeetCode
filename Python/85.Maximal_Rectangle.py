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

    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        max_area = 0
        height = [0] * len(matrix[0])
        row_length, col_length = len(matrix), len(matrix[0])
        
        for i in range(row_length):
            for j in range(col_length):
                if matrix[i][j] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
            
            area = self.largestRectangleArea(height)
            max_area = max(max_area, area)
            
        return max_area

if __name__ == '__main__':
    s = Solution()
    print(s.maximalRectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]))
    print(s.maximalRectangle([["0"]]))
    print(s.maximalRectangle([["1"]]))