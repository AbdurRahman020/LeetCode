struct ListNode {
    // value of the current node
    int val;
    // pointer to the next node in the list
    ListNode *next;
    // constructors
    ListNode() : val(0), next(nullptr) {}                       // default constructor
    ListNode(int x) : val(x), next(nullptr) {}                  // constructor with value parameter
    ListNode(int x, ListNode *next) : val(x), next(next) {}     // constructor with value and next node parameters
};

class Solution {
public:
    // function to delete a node from a singly linked list
    void deleteNode(ListNode* node) {
        // copy the value of the next node to the current node
        node -> val = node -> next -> val;
        // point the current node's next pointer to the node after the next node
        node -> next = node -> next -> next;
    }
};