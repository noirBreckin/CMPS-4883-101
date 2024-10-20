class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        // Count the frequency of each number
        for (int num : nums) {
            frequency[num]++;
        }

        // Use a min-heap to keep track of the top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (const auto& entry : frequency) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove the least frequent element
            }
        }

        // Extract the elements from the min-heap into a result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
