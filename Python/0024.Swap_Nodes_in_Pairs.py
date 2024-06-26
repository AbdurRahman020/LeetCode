from typing import Optional, List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def to_list(self) -> List[int]:
        """Convert the linked list to a Python list"""
        result: List[int] = []
        curr: Optional['ListNode'] = self
        while curr:
            result.append(curr.val)
            curr = curr.next
        return result
        
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        
        curr_node, next_node = head, head.next
        head, prev_node = next_node, curr_node

        while next_node:
            curr_node.next, next_node.next = next_node.next, curr_node
            if next_node != head:
                prev_node.next, prev_node = next_node, curr_node
            curr_node = curr_node.next
            if not curr_node:
                return head
            next_node = curr_node.next
        
        return head

if __name__ == '__main__':
    s = Solution()
    print(s.swapPairs(ListNode(1, ListNode(2, ListNode(3, ListNode(4))))).to_list())
    print(s.swapPairs(ListNode()).to_list())
    print(s.swapPairs(ListNode(1)).to_list())