class Solution:
    def diagonalSum(self, mat:list[list[int]]) -> int:
        m = len(mat)
        diag_sum = 0
        for i in range(m):
            diag_sum += mat[i][i] + mat[i][m-i-1]
        if m%2 != 0:
            j = m//2
            diag_sum -= mat[j][j]
        return diag_sum

if __name__ == '__main__':
    s = Solution()
    print(s.diagonalSum([[1,2,3],[4,5,6],[7,8,9]]))
    print(s.diagonalSum([[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]))
    print(s.diagonalSum([[5]]))