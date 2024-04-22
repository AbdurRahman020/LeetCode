class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x, y, dx, dy = 0, 0, 0, 1
        
        for i in instructions:
            if i == 'G':
                x, y = x + dx, y + dy
            if i == 'L':
                dx, dy = -dy, dx
            if i == 'R':
                dx, dy = dy, -dx
        
        return (x, y) == (0, 0) or (dx, dy) != (0, 1)

if __name__ == '__main__':
    s = Solution()
    print(s.isRobotBounded("GG"))
    print(s.isRobotBounded("GL"))
    print(s.isRobotBounded("GGLLGG"))