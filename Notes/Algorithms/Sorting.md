# Sorting

| Algorithm | Time Complexity | Data Structure | Limitations |
|---|---|---|---|
| Selection | O(N^2) | Sequence | |
| Bubble | O(N^2) | Sequence | |
| Merge | O(NlogN) | Sequence | |
| Quick | O(NlogN) to O(N^2) | Sequence |  |
| Heap | O(NlogN) | Sequence |  |
| Count | O(N+K) | Sequence | Requires well bounded values with K options |
| Radix | O(N) to O(D(N+B)) | Sequence | Efficiency depends on the number of digits and base  |
| Bucket | O(N) | Sequence | Requires a fairly normal distribution |

## Selection Sort

Repeatedly finds the minium (or max) and places it at the front (or back).

## Bubble Sort

Repeatedly swaps adjacent elements if they are in the wrong order.
- Needs a whole pass without any swaps for it to be fully sorted.
- Best case is if it's fully sorted (O(N)).

## Merge Sort

Break array into two and call merge sort on both halves. Merge resulting arrays.
- Form of divide and conquer.
- Goes through the whole process even if sorted.

## Quick Sort

Pick a pivot and place everything below to the left and above to the right. Repeat for both sides.
- Form of divide and conquer.
- If lowest or greatest is pivot every time, O(N^2), on average, pivot is in the middle so O(logN).

## Heap Sort

Build a binary heap. `heapify` ensures all nodes of a binary tree are greater (or less) than their child nodes. Child nodes are `2*I+1` (left) and `2*I+2` (right). Once the max is at the top, swap it with the end of the array then run heapify again to find the next max.

- Iteratively picks the next max via the max heap and moves it to the end.

## Counting Sort

Count the frequency of each item using the items as keys in an array. Then iterate through the array and expand each item by the count.

- Not comparison based.
- Requires well bounded values that can be used as 'key's in an contiguous.

## Radix Sort

Sort by least signficant digit. Then by next least significant digit. Etc. Untill all digits have been sorted.

Runtime is O(d(n+b)) where d = number of digits, n = number of elements, and b = base of digits.
```
> O(d(n+b))
> O(logbK(n+b)), where k = max value which has all digits
```
If we set K <= n^2:
```
> O(logbN^2(n+b))
> O(2NlogbN + 2blogbN)
> O(NlogbN)
```
Now if we set b = N:
```
> O(NlognN)
> O(N)
```

- Not comparison based.
- Uses counting sort as a subroutine (for each 'digit') which takes extra space.
- Can be used on binary inputs.

## Bucket Sort

Create N empty buckets (one for element) and insert `arr[i]` into `bucket[n*array[i]]`. Essentially enables 'counting' elements that can't be turned into keys to an array. When you have a normal distribution of elements, you average out to O(N)

- Not comparison based.