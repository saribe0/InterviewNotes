vector<int> working_stack;

vector<int> backtrack(vector<int>& candidates, int target, int startingIndex) {
    
    if (target <= 0) {
        return working_stack;
    }
    
    int pickIndex = startingIndex
    while (pickIndex+1 < candidates.size() && candidates[pickIndex] == candidates[pickIndex+1] ) {
        
        int pick = candidates[pickIndex];
        if (pickedIndex.count(pickIndex) && pickedIndex[pickIndex] > 0)
            continue;
        
        working_stack.push_back(pick);
            
        backtrack(candidates, target-pick, pickIndex);
        
        working_stack.pop_back();
        
        pickIndex++;
    }
}