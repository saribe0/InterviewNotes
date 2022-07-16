# General Notes

## Searching
When searcing for lots of datapoints, minimize the 'search' complexity.

Try to get the 'search' to take constant O(1) or O(logN) time

Consider pre-processing the input data

| Structure/Method | Build Complexity | Search Complexit | Comments |
|---|---|---|---|
| Sort | O(NlogN) | O(logN) | Easy to do with build ins & can run binary search. |
| Tree | O(NlogN) | O(logN) | Good with abnormal data that needs pre-processing as well such as ranges. |
| Hashmap | O(N) | O(1) | Good when hashable and when a hash makes sense. |

## Combinatorials & Permutations
Use backtracking to iterate the solutions. Can trim the exploration space.

## Two pointers
When dealing with an array, consider using two pointers that converge.

-> Typically end when lh > rh.

## When working with numbers

### Integers

num % 10 -> returns last digit
num / 10 -> trims off last digit
num * 10 -> shifts left one digit (adds 0 to the end)

### Binary

```C++
bitset<32> myBinaryNum(8);
int myIntNum = (int)(myBinaryNum.to_ulong());
```

## Corner cases

- Empty arrays
- Super large arrays - time/optimization corner cases
- Super large numbers - overflow

- Order of outputs
- Format of outputs

- Type of inputs/outputs -> chars, strings, ints, etc.

- Make sure sets go backwards when making updates