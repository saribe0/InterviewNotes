struct BinaryBinaryTrieNode {
    bool val;
    BinaryTrieNode* left;
    BinaryTrieNode* right;
    BinaryTrieNode(bool val): val(val), left(nullptr), right(nullptr) {}
};

struct BinaryTrie {
    BinaryTrieNode* root;
    
    Trie() {
        root = new BinaryTrieNode(false);
    }
    
    void addNode(bitset<32> newBitset, int num) {
        
        BinaryTrieNode* currentNode = root;
        
        for(int bit = 31; bit >= 0; bit--) {
            // Bit is set add to right 
            if (newBitset[bit]) {
                if (!currentNode->right) {
                    currentNode->right = new BinaryTrieNode(true);
                }
                currentNode = currentNode->right;
            }
            // Bit is not set add to left
            else {
                if (!(currentNode->left)) {
                    currentNode->left = new BinaryTrieNode(false);
                }
                currentNode = currentNode->left;
            }
        }
    }
};