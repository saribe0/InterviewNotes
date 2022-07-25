struct BFSState {
    // Each 'node' can be considered the 'state' that we're navigating
    // -> Could be multiple different variables (i.e., x, y, coins collected in a graph)
    /*
    State variables
    */

   // Keep track of predecessor if needed
   BFSState* predecessor;

   // If needed for hashing:
   bool operator==(const Key &other) const { 
    return (state==other.state && ...);
  }
}

template<>
struct std::hash<BFSState>
{
    std::size_t operator()(BFSState const& state) const noexcept
    {
        // Do something to hash the state, i.e.:
        std::size_t h1 = std::hash<string>{}(state.foo);
        std::size_t h2 = std::hash<int>{}(state.bar);
        std::size_t h3 = std::hash<int>{}(state.baz);
        return h1 ^ (h2 << 1) ^ (h3 << 2); // or use boost::hash_combine
    }
};

void BFS(/* input array */) {

    // Keep track of all states as they get created
    // -> May need an easy way to search states such as a hash map or set
    vector<BFSSTate*> allStates;

    //
    // Preprocess the data and build the BFS 'graph'
    //

    // BFS queue and visited set
    deque<BFSSTate*> bfsQueue;
    set<BFSState*> visitedStates;

    // If we are guaranteed to always pick a valid state, keep track of the order if needed
    vector<BFSState*> orderedStates;

    //
    // Populate the bfsQueue with any starting nodes (1+)
    // -> Mark these nodes as visited!

    while (!bfsQueue.empty()) {

        // 'visit' the state
        auto visitState = bfsQueue.front();
        bfsQueue.pop_front();

        // If always guaranteed to pick a valid state, update list of states
        // -> Don't do this not
        orderedStates.push_back(visitState);

        for (auto nextState: visitState->getNextStates()) {

            // If we've visited the state, handle appropriately
            if (visitedStates.count(nextState)) {
                // Skip, or if cycles not valid, return
            }

            // Determine if next state is valid (may not be necessary) and add it to the queue
            if (isValid(nextState)) {
                nextState->predecessor = visitState;
                visitidStates.insert(nextState);
                bfsQueue.push_back(nextState);
            }
        }
    }
}



