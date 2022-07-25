struct TrieNode {
    char letter;
    int count;
    bool isEndOfWord;
    unordered_map<char, TrieNode*> nextLetters;
    
    TrieNode(char letter): letter(letter), count(0), isEndOfWord(false) {}
    
    void insert(string_view word) {
        
        // Number of times we've seen this character
        count++;
        
        // If it's the last character, we're done
        if (word.size() == 1) {
            isEndOfWord = true;
            return;
        }
        
        // Create a node for the next character if it doesn't exist
        int nextLetter = word[1];
        if (nextLetters.count(nextLetter) == 0) {
            nextLetters[nextLetter] = new TrieNode(word[1]);
        }
        
        // Update the downstream nodes
        nextLetters[nextLetter]->insert(word.substr(1, word.size()-1));
    }
    
    void print() {
        cout << letter << ": " << count << ", " << isEndOfWord <<endl;
        for (auto next: nextLetters){
            if (next.second) {
                next.second->print();
            }
        }
    }
};

struct Trie {
    unordered_map<char, TrieNode*> startLetters;
    Trie() {}
    
    void insert(string_view word) {
        
        // Word must be at least a character
        if (word.size() == 0) return;
            
        // Create the tree node for the first character if it doesn't exist
        int startLetter = word[0];
        if (startLetters.count(startLetter) == 0) {
            startLetters[startLetter] = new TrieNode(startLetter);
        }
        
        // Insert the word at that character
        startLetters[startLetter]->insert(word);
    }
    
    void print() {
        for (auto next: startLetters){
            if (next.second) {
                next.second->print();
            }
        }
    }
};

