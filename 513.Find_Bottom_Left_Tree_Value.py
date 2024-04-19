class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def findBottomLeftValue(self, root:TreeNode) -> int:
        def dfs(root, depth):
            if not root:
                return 0, 0

            left = dfs(root.left, depth + 1)
            right = dfs(root.right, depth + 1)

            if left[1] == 0 and right[1] == 0:
                return root.val, depth
            if left[1] < right[1]:
                return right
            return left

        return dfs(root, 0)[0]

'''
        # BFS
        
        left = 0
        q = deque([root])

        while q:
            for i in range(len(q)):
                curr = q.popleft()
                if i == 0:
                    last = curr.val
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)

        return left
'''

if __name__ == '__main__':
    s = Solution()
    r1 = TreeNode(2, TreeNode(1), TreeNode(3))
    r2 = TreeNode(1, TreeNode(2, TreeNode(4)), TreeNode(3, TreeNode(5, TreeNode(7)), TreeNode(6)))
    print(s.findBottomLeftValue(r1))
    print(s.findBottomLeftValue(r2))