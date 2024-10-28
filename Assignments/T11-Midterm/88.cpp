class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       // Pointers for nums1 and nums2
        int i = m - 1; // Last element in nums1
        int j = n - 1; // Last element in nums2
        int k = m + n - 1; // Last position to fill in nums1

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        // No need to copy the remaining elements of nums1 since they are already in place
    }
};
