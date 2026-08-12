from typing import List
from collections import deque

class Solution:
    def floodFill1(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        start_color = image[sr][sc]
        
        def dfs(row: int, col: int) -> None:
            if (
                row < 0 or row >= len(image)
                or col < 0 or col >= len(image[0])
                or image[row][col] == color
                or image[row][col] != start_color
            ):
                return

            image[row][col] = color

            dfs(row - 1, col)
            dfs(row + 1, col)
            dfs(row, col + 1)
            dfs(row, col - 1)

        dfs(sr, sc)

        return image

    def floodFill2(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        queue = deque([(sr, sc)])

        rows, cols = len(image), len(image[0])
        
        original_color = image[sr][sc]

        if original_color == color:
            return image

        image[sr][sc] = color

        while queue:
            curr_row, curr_col = queue.popleft()

            for row_change, col_change in directions:
                next_row = curr_row + row_change
                next_col = curr_col + col_change

                if (
                    0 <= next_row < rows and
                    0 <= next_col < cols and
                    image[next_row][next_col] == original_color
                ):

                    image[next_row][next_col] = color
                    queue.append((next_row, next_col))

        return image

if __name__ == '__main__':
    s = Solution()

    print(s.floodFill1([[1,1,1], [1,1,0], [1,0,1]], 1, 1, 2)) 
    print(s.floodFill1([[0,0,0], [0,0,0]], 0, 0, 0))

    print(s.floodFill2([[1,1,1], [1,1,0], [1,0,1]], 1, 1, 2)) 
    print(s.floodFill2([[0,0,0], [0,0,0]], 0, 0, 0))
