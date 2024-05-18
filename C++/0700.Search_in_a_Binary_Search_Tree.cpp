struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
        return nullptr;
        if (val > root->val) {
            return searchBST(root->right, val);
        }
        else if (val < root->val) {
            return searchBST(root->left, val);
        }
        else {
            return root;
        }
    }
};

int main() {
    Solution s;
    TreeNode* r = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
    TreeNode* r1 = s.searchBST(r, 2);
    TreeNode* r2 = s.searchBST(r, 5);
}