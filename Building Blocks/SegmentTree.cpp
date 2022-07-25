struct SegmentTreeNode {
    int min;
    int max;
    int mid;
    int sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(): sum(0), left(nullptr), right(nullptr) {}
    SegmentTreeNode(int min, int max) : sum(0), min(min), max(max), left(nullptr), right(nullptr) {
        mid = (max - min)/2 + min;
    }
    SegmentTreeNode(int min, int max, int sum) : sum(sum), min(min), max(max), left(nullptr), right(nullptr) {
        mid = (max - min)/2 + min;
    }
    
    bool matchesNodeRange(int rangeMin, int rangeMax) {
        return rangeMin == min && rangeMax == max;
    }
    
    void updateTreeWithVal(int val) {
        sum += val;
        if (left) left->updateTreeWithVal(val);
        if (right) right->updateTreeWithVal(val);
    }
               
    void update(int rangeMin, int rangeMax, int val) {
               
        // Range matches node perfectly, update the tree below with the value.
        if (matchesNodeRange(rangeMin, rangeMax)) {
            updateTreeWithVal(val);
            return;
        }
        
        // Not a perfect match, so make sure child nodes exist
        if (!left) left = new SegmentTreeNode(min, mid, sum);
        if (!right) right = new SegmentTreeNode(mid+1, max, sum);
        
        // Update this node
        sum += val;

        // Spans both children nodes, both must be updated and the range split
        if (rangeMin <= mid && rangeMax > mid) {
            left->update(rangeMin, mid, val);
            right->update(mid+1, rangeMax, val);
        }
        
        // Only update left node
        else if (rangeMax <= mid) {
            left->update(rangeMin, rangeMax, val);
        }
        
        // Only update right node
        else if (rangeMin > mid) {
            right->update(rangeMin, rangeMax, val);
        }
    }
    
    int querySumForVal(int queryVal) {
        
        // Left than the middle and no left
        if (queryVal <= mid) {
            if (!left) return sum;
            return left->querySumForVal(queryVal);
        }
        else {
            if (!right) return sum;
            return right->querySumForVal(queryVal);
        }
    }
};

struct SegmentTree {
    
    SegmentTreeNode *root;
    SegmentTree(): root(nullptr) {}
    SegmentTree(int min, int max): root(nullptr) {
        root = new SegmentTreeNode(min, max);
    }
    
    void addRange(int min, int max, int val) {
        root->update(min, max, val);
    }
    
    int querySumForVal(int queryVal) {
        return root->querySumForVal(queryVal);
    }

};

