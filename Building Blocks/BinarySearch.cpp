
int binarySearch(vector<int>& nums, int lhIndex, int rhIndex, int target) {
    // Handle some corner cases
    if (<end case>)
        return <something>;
    
    int midIndex = lhIndex + (rhIndex - lhIndex) / 2;
    if (target > nums[midIndex])
        return binarySearch(nums, midIndex, rhIndex, target);
    else
        return binarySearch(nums, lhIndex, midIndex, target);
}