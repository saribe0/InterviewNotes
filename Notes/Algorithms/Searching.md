# Searching

| Algorithm | Complexity | Data Structure | Limitations |
|---|---|---|---|
| Linear | O(N) | Sequence | |
| Binary | O(logN) | Sequence | Must be sorted |

## Linear Search

Iterate over items to find the one you're looking for

## Binary Search

Split the sequence in two and only check the side that has the target item. Repeat.

# Graphs

| Algorithm | Complexity | Summary | Applications | Limitations |
|---|---|---|---|---|
| BFS | O(V+E) | Works way through graph by 'layer' | Search graph, Detect cycles, Check bipartite, Check strongly connected |  |
| DFS | O(V+E) | Explores deep then backtracks | Search graph, Detect cycles, Check bipartite, Check strongly connected |  |
| Dijstra's | O(ElogV) to (V^2) | Greedily grabs the node that will keep the path the shortest. | Shortest path to ALL nodes. | Can not have negative cycles |
| Kosaraju's | O(V+E) | 2x DFS, second in reverse of DFS path | Find all strongly connected components |  |
| Bellman Fords's | O(VE) | DP evaluation of shortest path to source | Finds shortest path to ALL nodes, Finds negative cycles from node |  |
| Floyd Warshall's | O(V^3) | DP evaluation of all pairs shortest paths | Finds shortest path to and from ALL nodes, Finds negative cycles from node |  |

## Breadth First Search (BFS)

Visits all available nodes and adds each one to a queue to go start from next.

- Uses a visited array/structure
- Only reaches vertices from a given source, have to go from ALL nodes to ensure all vertices are visitied
    - Do not have to revisit visited nodes
    - Can handle directed/undirected graphs as even untouched nodes will be visited

## Depth First Search (DFS)

Explores as far as possible along each branch then backtracks.

- Uses a visited array/structure
- Often implemented recursively using the same visited array
    - At each node, call DFS on it's adjacent nodes if they haven't been visited yet.
- Only reaches reachable nodes. For all nodes, run DFS from all nodes, skipping if they've been visited.

Applications:
- Can detect cycles
- Can find paths between given points or puzzles like mazes
- Can check if a graph is bipartite

## Dijstra's Algorithm - Shortest Path

Greedily pick the vertex that keeps the current path the shortest. Need to keep track of the 'current' path to all other nodes as well.

- Can be used on directed and undierected graphs
- Does not work on graphs with negative weight cycles

To go from O(V^2) to O(ElogV + VlogV), we can use an min heap (priority queue) to keep track of the shortest path options.

To go from O(ElogV + VlogV) to O(E + VlogV), we can use a fibonacci heap which takes O(1) to remove the min value.

## Kosaraju's Algorithm - Strongly Connected Components

Run DFS then again on the reverse of the nodes discovered by DFS.

- Finds all strongly connected components

## Bellman Ford's Algorithm - Shortest Path

Determine the shortest distances from the source node via DP-like algorithm. Then check to see if we can get shorter. If so, there must be a negative cycle.

1. Initialize distances from source to all other vertices as infinite, distance to itself as 0.

2. Do V times:
    For each edge:
        If dist[v] > dist[u] + weight uv, update dist[v]
            dist[v] = dist[u] + weight uv
3. For each edge:
        If dist[v] > dist[u] + weight uv
            Negative cycle

- Shortest distances with 1 edge. Then shortest distances with 2 edges. After ith iteration, shortest path for i edges are called.
- There are |V|-1 edges total (assuming no self-cycles)

Benefits
- Works well for distributed systems
- Works with negative weights
- Can be made for all pairs shortest paths in O(V^E)

Limitations
- To handle disconnected graphs, repeat for all vertices

## Floyd Warshall's Algorithm - All Pairs Shortest Path

All pairs shortest path problem. 

Graph keeps track of shortest distance between source and destination. Every iteration, we check to see if the next node will shorten any of the paths. Once we've gone through all nodes, we'll have all pairs of vertecies shortests paths.

- Dynamic programming approach that builds up the shortest paths using all nodes
