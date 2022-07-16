# C++ STL Containers

| Container | Insert/Remove at beginning | Insert/Remove at end | Random Insert/Removal | Access at beginning | Access at end | Random Access | Size | Count | Merge | Sort | Reverse | Unique |
|-----------|---|---|---|---|---|---|---|---|---|---|---|---|
| Array       |  |  |  | O(1) | O(1) | O(1) | O(1) |  |  |   |   |   |   | 
| Vector       | O(N) | O(1) | O(N) | O(1) | O(1) | O(1) | O(1) |  |  |   |   |   |   | 
| Forward List | O(1) | O(N) | O(N) | O(1) | O(N) | O(N) | O(N) |  | O(N) | O(NlogN) | O(N) | O(N) |
| List      | O(1) | O(1) | O(N) | O(1) | O(1) | O(N) | O(1) |  | O(N) | O(NlogN) | O(N) | O(N) |
| Deque     | O(1) | O(1) | O(N) | O(1) | O(1) | O(1) | O(1) |  |   |   |   |   | 
| Queue     | removal: O(1) | insert: O(1) |  | O(1) | O(1) |  | O(1) |  |  |   |   |   |   | 
| Priority Queue     | removal: O(logN) | insert: O(logN) |  | O(1) |  |  | O(1) |  |  |   |   |   |   |
| Stack       |  | O(1) |   |  | O(1) |  | O(1) |  |  |   |   |   |   |  
| Set       |  |  | O(logN)  |  |  | O(logN) | O(1) | O(logN) |  |   |   |   |   | 
| Multiset       |  |  | O(logN)  |  |  | O(logN) | O(1) | O(logN) |  |   |   |   |   |
| Unordered Set       |  |  | O(1)  |  |  | O(1) | O(1) | O(1) |  |   |   |   |   | 
| Unordered Multiset       |  |  | O(1)  |  |  | O(1) | O(1) | O(1) |  |   |   |   |   |  
| Map       |  |  | O(logN) |  |  | O(logN) | O(1) | O(logN) |  |   |   |   |   | 
| Multimap  |  |  | O(logN) |  |  | O(logN) | O(1) | O(logN) |  |   |   |   |   | 
| Unordered Map       |  |  | O(1) |  |  | O(1) | O(1) | O(1) |  |   |   |   |   | 
| Unordered Multimap       |  |  | O(1) |  |  | O(1) | O(1) | O(1) |  |   |   |   |   | 

## Array

A fixed size container that stores elements contiguously in memory.

- Does not keep any data other than it's elements.
- Essentially a wrapper for a C array.

## Vector

A container of elements stored contiguously in memory. 

- Size can change dynamically.
- Very efficient at random element accesses.

## Forward List

One directional linked list. Can only be iterated over in one direction though slightly more efficient because there's no backwards pointer to store & update.

- Preforms better for algorithms that require random insertion & removal where the iterator has already been obtained, like sorting.
- Since the `forward_list` was designed with efficiency in mind, it contains no `size` method or internal state as it would add space & time overhead.
- Lacks direct access to elements by position (O(N) to get to a position).

## List

Doubly linked list that can be iterated over in either direction.

- Preforms better for algorithms that require random insertion & removal where the iterator has already been obtained, like sorting.
- Lacks direct access to elements by position (O(N) to get to a position).
- Requires some extra memory for doubly linking relative to the forward list.

## Deque ("deck")

Double Ended Queue - a queue that can be expanded or contracted from either side.

- Random access iterators.
- Similar functionality to a vector but with efficient insertion/deletion at beginning as well.
- Can *not* rely on contiguous storage of elements - must use iterators.

## Queue

First in, first out queue where elements are inserted on one end and extracted from the other. 

- Implemented as container adapters that wrap other containers (typically deque or list)

## Priority Queue

Essentially a **heap** where the first element is either the maximum or minimum value. 

- Implemented as container adapters that wrap other containers (typically vector or deque).
- "Top" of the queue is the "back" of the underlying container where elements are popped from.
- Requires `make_heap`, `push_heap`, and `pop_heap` to be called on random inserts.

### Bonus - Fibonacci Heap

A collection of trees with a min/max heap property. All trees can take any shape. All tree roots are connected using a circular doubly linked list.

Fibonnacci heaps take a "lazy" approach where they mostly link trees. 

- Find Min O(1)
- Delete Min O(logN)
- Insert O(1)
- Decrease Key O(1)
- Merge O(1)

The only one here that is quite taxing is the delete min which take sthe same as other heaps.

## Stack

Last in, first ou queue where the last element to be inserted is extracted first.

- Implemented as container adapters that wrap other containers (typically vector, deque, or list).

## Set

Ordered containers of unique elements.

- Elements are **sorted** internally.
- Elements must be unique.

## Multiset

Ordered containers of elements where elements are not distinct.

- Elements are **sorted** internally.
- Typically implemented through binary search trees.

## Unordered Set

A container of unique elements.

- Elements are hashed.
- Elements must be unique.

## Unordered Multiset

A container of elements where elements are not distinct.

- Elements are hashed.


## Map

An associative storage container using *key value* pairs.

- Keys must be unique.
- Elements are **sorted** by *key* internally.

## Multimap

An associative storage container using *key value* pairs where keys are not distinct.

- Elements are **sorted** by *key* internally.
- Typically implemented through binary search trees.

## Unordered Map

An associative storage container using *key value* pairs where keys *are not ordered*.

- Keys must be unique.
- Values are identified by hashing the key.
- Otherwise known as a hash map

## Unordered Multimap

An associative storage container using *key value* pairs where keys *are not ordered or unique*.

- Values are identified by hashing the key.
- Otherwise known as a hash map
