#include <queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Keep only k elements in the heap
            }
        }
        return minHeap.top(); // Root of the heap is the k-th largest element
    }
};
