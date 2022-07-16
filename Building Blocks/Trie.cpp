    struct TrieNode {
        bool val;
        vector<int> vals;
        TrieNode* left;
        TrieNode* right;
        TrieNode(bool val): val(val), left(nullptr), right(nullptr) {}
    };
    
    struct Trie {
        TrieNode* root;
        
        Trie() {
            root = new TrieNode(false);
        }
        
        void addNode(bitset<32> newBitset, int num) {
            
            TrieNode* currentNode = root;
            
            for(int bit = 31; bit >= 0; bit--) {
                // Bit is set add to right 
                if (newBitset[bit]) {
                    if (!currentNode->right) {
                        currentNode->right = new TrieNode(true);
                    }
                    currentNode = currentNode->right;
                }
                else {
                    if (!(currentNode->left)) {
                        currentNode->left = new TrieNode(false);
                    }
                    currentNode = currentNode->left;
                }
                currentNode->vals.push_back(num);
            }
        }