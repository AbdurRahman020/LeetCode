class Solution(object):
    def exist(self, board:list[list[str]], word:str) -> bool:
        row_length, col_length = len(board), len(board[0])
        
        def dfs(r, c, current):
            if current == len(word):
                return True
            if r < 0 or c < 0 or r >= row_length or c >= col_length or \
              board[r][c] == '' or word[current] != board[r][c]:
                return False
            
            cache = board[r][c]
            board[r][c] = ''
            
            if dfs(r+1, c, current+1) or dfs(r-1, c, current+1) or \
                 dfs(r, c+1, current+1) or dfs(r, c-1, current+1):
                return True
            
            board[r][c] = cache
            return False
        
        return any(dfs(i, j, 0) for i in range(row_length) for j in range(col_length))

if __name__ == '__main__':
    s = Solution()
    b = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    print(s.exist(b, 'ABCCED'))
    b = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    print(s.exist(b, 'ABCB'))
    b = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    print(s.exist(b, 'SEE'))