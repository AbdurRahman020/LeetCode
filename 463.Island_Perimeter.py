class Solution:
    def islandPerimeter(self, grid:list[list[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        perimeter = 0

        def dfs(r,c):
            if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == 0:
                return 1
            if grid[r][c] == -1:
                return 0
            
            grid[r][c] = -1 

            perimeter = dfs(r+1, c)
            perimeter += dfs(r-1, c)
            perimeter += dfs(r, c+1)
            perimeter += dfs(r, c-1)

            return perimeter
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    perimeter += dfs(i,j)
        
        return perimeter 

if __name__ == '__main__':
    s = Solution()
    print(s.islandPerimeter([[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]))
    print(s.islandPerimeter([[1]]))
    print(s.islandPerimeter([[1,0]]))