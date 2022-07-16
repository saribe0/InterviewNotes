class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                
        // Copy nums1
        vector<int> nums1Copy;
        for(int i = 0; i < m; i++){
            nums1Copy.push_back(nums1[i]);
        }
        
        // Go through both nums1 and nums2 pulling the smallest from each into nums1
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m && j < n) {
            if (nums1Copy[i] > nums2[j]) {
                nums1[k] = nums2[j];
                k++;
                j++;
            }
            else {
                nums1[k] = nums1Copy[i];
                k++;
                i++;
            }
        }
        // One of the arrays is exhausted, copy the lefovers
        for(; i<m; i++, k++) {
            nums1[k] = nums1Copy[i];
        }
        for(; j<n; j++, k++) {
            nums1[k] = nums2[j];
        }
    }
};