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
    // function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // create a new node to store the result
        ListNode* curr = new ListNode();
        // pointer to the head of the result list
        ListNode* head = curr;
        // variable to store the carry
        int carry = 0;

        // iterate through the lists until both lists are exhausted and no carry remains
        while (l1 || l2 || carry) {
            // get the values of the current nodes or default to 0 if the node is nullptr
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int val = val1 + val2 + carry;

            // calculate the sum and carry
            carry = val / 10;
            val = val % 10;

            // create a new node with the calculated value and add it to the result list
            curr->next = new ListNode(val);
            curr = curr->next;

            // move to the next nodes in the input lists if they are not nullptr
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        // return the result list (excluding the dummy head)
        return head->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = s.addTwoNumbers(l1, l2);
    ListNode* l3 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))))));
    ListNode* l4 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    ListNode* result2 = s.addTwoNumbers(l3, l4);
    return 0;
}