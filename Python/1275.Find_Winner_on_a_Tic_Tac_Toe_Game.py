class Solution:
    def tictactoe(self, moves: list[list[int]]) -> str:
        a, b = [0]*8, [0]*8
        
        for i in range(len(moves)):
            row, col = moves[i]
            if i%2 == 0:
                player = a
            else:
                player = b
            
            player[row] += 1
            player[col+3] += 1
            
            if row == col:
                player[6] += 1
            if row == 2 - col:
                player[7] += 1
                
        for i in range(8):
            if a[i] == 3:
                return 'A'
            if b[i] == 3:
                return 'B'
        
        return 'Draw' if len(moves) == 9 else 'Pending'

if __name__ == '__main__':
    s = Solution()
    print(s.tictactoe([[0,0],[2,0],[1,1],[2,1],[2,2]]))
    print(s.tictactoe([[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]))
    print(s.tictactoe([[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]))