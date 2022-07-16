
// Linked List style node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Binary tree style node
struct TreeNode {
    int val;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode() : val(0), leftChild(nullptr), rightChild(nullptr) {}
    TreeNode(int x) : val(x), leftChild(nullptr), rightChild(nullptr) {}
    TreeNode(int x, TreeNode *leftChild, TreeNode *rightChild) : val(x), leftChild(leftChild), rightChild(rightChild) {}
};

