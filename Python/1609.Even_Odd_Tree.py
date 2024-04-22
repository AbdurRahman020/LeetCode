from collections import deque

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        level = 0
        queue = deque()
        queue.append(root)
        
        while queue:
            prev_val = None
            for _ in range(len(queue)):
                root = queue.popleft()
                
                if level %2 == 0:
                    if root.val % 2 != 1 or (prev_val is not None and prev_val >= root.val):
                        return False
                else:
                    if root.val % 2 != 0 or (prev_val is not None and prev_val <= root.val):
                        return False
                
                prev_val = root.val

                if root.left:
                    queue.append(root.left)
                if root.right:
                    queue.append(root.right)
            
            level += 1
            
        return True

if __name__ == '__main__':
    s = Solution()
    r1 = TreeNode(1, TreeNode(10, TreeNode(3, TreeNode(12), TreeNode(8))), TreeNode(4, TreeNode(7, TreeNode(6)), TreeNode(9, None, TreeNode(2))))
    r2 = TreeNode(5, TreeNode(4, TreeNode(3), TreeNode(3)), TreeNode(2, TreeNode(7)))
    r3 = TreeNode(5, TreeNode(9, TreeNode(3), TreeNode(5)), TreeNode(1, TreeNode(7)))
    print(s.isEvenOddTree(r1))
    print(s.isEvenOddTree(r2))
    print(s.isEvenOddTree(r3))